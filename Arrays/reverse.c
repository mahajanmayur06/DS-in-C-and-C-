#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int m, int n)
{
    int t = arr[m];
    arr[m] = arr[n];
    arr[n] = t;
}
// void reverse(int *arr,int f, int r)
// {
//     if (f >= r)
//         return;
//     swap(arr,f,r);
//     reverse(arr,f+1,r-1);
// }
void reverse(int *arr,int i, int n)
{
    if (i >= n/2)
        return;
    swap(arr,i,n-i-1);
    reverse(arr,i+1,n);
}

void reversePrint(int *arr, int n)
{
    int *ptr = (arr + n - 1);
    while (ptr != arr)
    {
        printf("%d ", *ptr);
        ptr--;
    }
    printf("%d\n", *ptr);
}
int main()
{
    int n;
    printf("Enter n ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", (arr + i));
    reverse(arr,0, n);
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    return 0;
}