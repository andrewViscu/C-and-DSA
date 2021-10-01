#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size) {
    for(int i = 0; i < size; i++) {
        int min_index = i;
        for(int j = i+1; j < size; j++){
            if(array[j] < array[min_index]) {
                min_index = j;
            }
        }
        swap(&array[min_index], &array[i]);

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

    selectionSort(data, size);
    printArray(data, size);
    return 0;
}
