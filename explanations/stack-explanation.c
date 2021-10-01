/* 
Application memory can be divided into 4 segments:
* Code (text) - Instructions.
* Static / global - not declared inside of function, have the whole time of an application, accessible anywhere while app is running.
* Stack - Store all the info of function calls and all the local variables, they live only until the time the function is executed.
These 4 does not grow while using the application.
and there's 
* Heap
*/

//Bad code below
#include <stdio.h>

int total;
int Square(int x) {
    return x * x;
}

int SquareOfSum(int x, int y) {
    int z = Square(x + y);
    return z;
}

int main(int argc, char const *argv[])
{
    int a = 4, b = 8;
    total = SquareOfSum(a, b);
    printf("otput = %d", total);
    return 0;
}

/*
When the program is executed, main method is involved,
some memory from stack is allocated for execution of main()
this memory is called stack frame
it's calculated when the program is compiling
in our program, at the beginning, stack contains main(), a, b
when SqOfSm method is called by main, the stack frame is allocated for it
at any time during the exec of the application, the function
on the top is executing and rest is paused

STACK
--> (Running) stack frame 3: (Sq(), x)
--> (Paused) stack frame 2: (SqOfSm(), x, y, z)
--> (Paused) stack frame 1: (main(), a, b)

GLOBAL
total

when function finishes, it pops out of a stack and next function is called.
when main() finishes executing, stack frame is empty, 
program is finished, so global is also cleared

OS allocates memory for stack
if call stack is too big and we exhaust all memory, 
stackoverflow happens and the program crashes

it's impossible to manipulate the scope of variable if it's on the stack
also, if large data type is declared as local variable, then
the size of it should be known at compile time only.
*/
