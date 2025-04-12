#include <stdio.h>
#include <stdlib.h>


void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int lArr[n1], rArr[n2];

    
    for (i = 0; i < n1; i++)
        lArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rArr[j] = arr[mid + 1 + j];

    
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (lArr[i] <= rArr[j]) {
            arr[k] = lArr[i];
            i++;
        }
        else {
            arr[k] = rArr[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = lArr[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        arr[k] = rArr[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
      
        
        int mid = left + (right - left) / 2;

    
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {15,5,22,8,1,3,14 };
    int N = sizeof(arr) / sizeof(arr[0]);
  
    printf("Given array is:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, N - 1);

    printf("\nSorted array is:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}