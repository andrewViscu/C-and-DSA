#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr[10] = {4, 5, 2, 3, 6, 9, 14, 54, 21, 1};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    printf("length - %d", arrLength);
    for (int i = 0; i < arrLength - 1; i++) 
    {
        int temp = 0;
        int j = i + 1;
        printf("%d iteration", i);
        if(arr[i] > arr[j]) { 
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    for (int j = 0; j < arrLength - 1; j++) {
        
        printf("%d, \n", arr[j]);
    }
    
    return 0;
}
