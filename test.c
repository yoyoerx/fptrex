#include <stdio.h>
#include "fptr.h"

//the external function to be set and run
void MyTest(void){
	printf("external MyTest in test.c\n");
}

//the external version of the SetTest function
void SetTest(void){
	printf("external SetTest in test.c\n");
	//set the global VFptr test variable to
	// the function we would like to use, in 
	// this case MyTest
	test = MyTest;
	//test = &MyTest;
	//test = *MyTest;
	// any of these work here
}
