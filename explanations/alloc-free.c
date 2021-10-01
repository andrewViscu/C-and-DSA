/*
//malloc - void* malloc(size_t size)

int *p = (int*)malloc(3*sizeof(int));
// *p = 2, same as p[0]
// *(p+1) = 4, same as p[1]
// *(p+2) = 2, same as p[2]

free(p);

//calloc - void* calloc(size_t num, size_t size)

int *p = (int*)calloc(3, sizeof(int));
one more difference - when malloc allocates some amount of memory,
it does not initialize the bytes with any values.
if you do not fill in any value in malloc, you'll have some garbage there.
if you use calloc, it sets all bytes positions with 0s.

//realloc - void* realloc(void* ptr, size_t size)

int *m = realloc(*p, sizeof(int))
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    //int A[n]; - illegal
    int *A = (int*)calloc(n,sizeof(int)); //dynamically allocated array
    //if malloc would've been called instead, it would have had garbage values. 
    
    // for(int i = 0; i < n; i++){
    //     A[i] = i+1;
    // }

    int *B = (int*)realloc(A, 2*n*sizeof(int));

    //realloc(A, 0) - equivalent to free(A)
    //realloc(NULL, n*sizeof(int)) - equivalent to malloc
    printf("Prev block addess = %d, new address = %d\n", A, B);
    for(int i = 0; i<2*n;i++) {
        printf("%d\n ", A[i]);
    }
    return 0;
}
