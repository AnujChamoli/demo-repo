#include <stdio.h>

int binarySearch_recursive(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    
    if (x == array[mid])
      return mid;

    if (x > array[mid])
      return binarySearch_recursive(array, x, mid + 1, high);

    return binarySearch_recursive(array, x, low, mid - 1);
  }

  return -1;
}

int main(void) {
  int array[] = {13, 14, 15, 16, 17, 18, 19};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 14;
  int result = binarySearch_recursive(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}