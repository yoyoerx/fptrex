/*
fptr.c

an example of how to efficiently have an 
optional function included in a program.
Rather than define an empty weak function 
locally (which requires processor overhead 
to jump to and from), this uses a function
pointer that can be set to NULL and skipped.

By default, the test function is NULL, but
the user can create a SetTest() to set the 
test function pointer to a function of their
choosing/creation.  

This should help efficiency in loops. SetTest()
should be called from outside and before the
loop and then

	if(test){
		test();
	}

can be placed in the loop where appropriate.



Tested in x86_64-pc-cygwin with gcc 5.3.0

To run: use included build.sh or do it 
yourself as shown below

#complie the objects
gcc -c -o fptr.o fptr.c
gcc -c -o test.o test.c
gcc -c -o test2.o test2.c
#link into executables
gcc -o fptr.exe fptr.o 
gcc -o fptr-test.exe fptr.o test.o
gcc -o fptr-test2.exe fptr.o test2.o


Expected output for each executable:

$ ./fptr.exe
weak SetTest
0x0

$ ./fptr-test.exe
external SetTest in test.c
0x401160
external MyTest in test.c
external MyTest in test.c

$ ./fptr-test2.exe
external SetTest in test2.c
0x401160
external MyTest2 in test2.c
external MyTest2 in test2.c

*/

#include <stdio.h>
#include "fptr.h"


//declare and define the global VFptr
// test variable to NULL
VFptr test = NULL;

//A weakly defined version of SetTest
// in the event that an external function
// is not provided.
__attribute__((weak))
void SetTest(void){
	printf("weak SetTest\n");
	//set global VFptr test variable to
	// NULL, as there is no function to
	// run in the default case.
	test = NULL;
}

int main(){

	//call for test function to be set
	// this will either be the weak local
	// function or an external function
	// if provided
	SetTest();

	//print the address of the function 
	// set for test (for information only)
	printf("0x%X\n", test);

	//if test is NULL, do not call the
	// function otherwise, we call the
	// function set in test
	if(test) {
		//either method works for calling
		// the function in the function 
		// pointer
		test();
		(*test)();
	}
	
	//end of main
	return 0;
}
