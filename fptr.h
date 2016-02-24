#ifndef FPTR_H
#define FPTR_H

//defining VFptr as a function pointer to a function
// that takes no arguments and returns nothing
typedef void (*VFptr)(void);

//setting a global variable to the function pointer
// and calling it "test"
extern VFptr test;

//prototype for the function that sets what the
// testing function is. This is weakly declared in
// fptr.c so it can be overridden in implementation
void SetTest(void);

#endif
