#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
  
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}
int main()
{
    int arr[] = {23,75,34,86,22,45,23,8,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    printf("2nd largest elements: %d", arr[n-2]);
    return 0;
}