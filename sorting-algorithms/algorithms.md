## Bubble Sort

element and element next to it compare, **if arr[i] is bigger, than arr[i+1]**, they **swap**.
13, 16, 12
13, 12, 16
12, 13, 16

bubbleSort(array)
  for i <- 1 to indexOfLastUnsortedElement-1
    if leftElement > rightElement
      swap leftElement and rightElement
end bubbleSort

Time complexity - O(n^2)

## Optimized Bubble Sort

swapped is set to false, **if by the end** of the iteration it's still **false**, then it means that it's **sorted**. quits faster.

bubbleSort(array)
  swapped <- false
  for i <- 1 to indexOfLastUnsortedElement-1
    if leftElement > rightElement
      swap leftElement and rightElement
      swapped <- true
end bubbleSort

## Selection Sort

selects the **first element**, sets it as **"smallest"**
**compares with the second element**. if it's **smaller**, **asign** it as a new minimum, otherwise do nothing.
**repeat** until the last element.
after each iteration, minimum is placed in the front of unsorted list.

Time complexity - O(n^2)

## Insertion Sort



## Merge Sort

we **divide** endlessly the array into arrays until they're 2 or 3 elements. 
we **compare the pairs** of arrays between each other and **sort**.
then **merge into one** and compare with other arrays and **sort**.
then done.


## Quick sort
takes a pivot from the far right. everything that's lower than it - on the left,
everything higher - on the right
then these two groups repeat the process above.

