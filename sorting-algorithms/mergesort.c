#include <stdio.h>

void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2]; //3 , 3

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i]; // L[0, 2, 1] => A[0, 2, 1] => [-6, 3, 20]
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j]; //M[0, 1, 2] => A[3, 4, 5] => [-99, 1, 110]

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) { //0 < 3 && 0 < 3
    if (L[i] <= M[j]) {
      arr[k] = L[i]; //1: -6, 3: 3, 4: 20 
      i++; //1, 2, 3
    } else {
      arr[k] = M[j]; //0: -99, 2: 1, 5: 110
      j++; //1, 2, 3
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
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
    int data[] = {-6, 20, 3, -99, 1, 110};
    int size = sizeof(data)/sizeof(data[0]);

    mergeSort(data, 0, size - 1);
    printArray(data, size);
    return 0;
}
