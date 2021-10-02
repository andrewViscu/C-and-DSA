
#include <stdio.h>
#include <stdlib.h>

// Function to get the largest element from an array
int getMax(int array[], int size) {
    //set first as max from the big array (n-m)
  int max = array[0];
  //get the actual max
  for (int i = 1; i < size; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  int *output = (int*)malloc(size*sizeof(int)+sizeof(int));
  //set first as max for small array (0-9)
  int max = (array[0] / place) % 10;
  //get the actual max
  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max )
      max = array[i];
  }
  int *count = (int*)malloc(max*sizeof(int)+sizeof(int));
  // fill the array with 0s
  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  // Calculate cumulative count
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixSort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10) 
    countingSort(array, size, place);
}

// Print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

// Driver code
int main() {
  //CANNOT BE NEGATIVE INTEGER!! LEARNED IT THE HARD WAY.
  int data[] = {6, 20, 3, 99, 1, 110, 69, 5234};
  int n = sizeof(data) / sizeof(data[0]);
  radixSort(data, n);
  printArray(data, n);
}