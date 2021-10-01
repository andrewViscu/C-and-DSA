/* 
Heap is free store of memory. Application heap, unlike stack
is not fixed, it's size can vary in the life time of the application
and there's no set rule for allocation/deallocation of the set memory.
A programmer can controll how much memory to use from the heap, heap can grow
as long as you don't run out of memory on the system itself.
(it's also very dangerous and we need to be careful).
It's also called  dynamic memory.
Using the heap is reffered as "dynamic memory allocation."
(application heap has nothing to do with data-structure heap)


 there's 4 functions in C:
 malloc, calloc, realloc, free
 there's also "new" and "delete" in C++

*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a; //goes on stack
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = (int*)malloc(sizeof(int)); //new block
    //if we don't use free(), previous block is still in the heap
    //and it will live until the end of the program.
    *p = 20;
    free(p);
    int n = 20; //array size
    p = (int*)malloc(n*sizeof(int)); 
    free(p);
    return 0;
}

/* In C++ it would look like this:

#include<stdio.h>
#include<stdlib.h>
int main() {
    int a;
    int *p;
    p = new int;
    *p = 10;
    delete p;
    int n = 20;
    p = new int[n];
    delete p;
}
*/