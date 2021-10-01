#include <stdio.h>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int data[] = {-6, 20, 3, -99, 1, 110, 69};
    int size = sizeof(data)/sizeof(data[0]);

    Some_sort(data, size);
    printArray(data, size);
    return 0;
}
