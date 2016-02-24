#include <stdio.h>
#include "fptr.h"

//the external function to be set and run
void MyTest2(void){
	printf("external MyTest2 in test2.c\n");
}

//the external version of the SetTest function
void SetTest(void){
	printf("external SetTest in test2.c\n");
	//set the global VFptr test variable to
	// the function we would like to use, in 
	// this case MyTest2
	test = MyTest2;
	//test = &MyTest;
	//test = *MyTest;
	// any of these work here
}
