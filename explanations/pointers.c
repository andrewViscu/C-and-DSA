#include <stdio.h>
#include <stdlib.h>

// P O I N T E R S
int main(int argc, char const *argv[])
{
    int num = 10;
    printf("%p \n", &num);

    int *pNum = &num; //storing a pointer in a variable
    printf("%p \n", pNum);
    printf("%d \n", *pNum);
    return 0;
}
