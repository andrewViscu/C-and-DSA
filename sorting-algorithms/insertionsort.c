#include <stdio.h>

void insertionSort(int array[], int size) {
    for(int i = 1; i < size; i++){
        int key = array[i]; 
        int j = i - 1;
        while(key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j+1] = key;
    }
}

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

    insertionSort(data, size);
    printArray(data, size);
    return 0;
}
