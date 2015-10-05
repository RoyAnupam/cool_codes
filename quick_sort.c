#include <stdio.h>
#define MAX 1000

int arr[MAX];

int FindPivot(int arr[], int start, int end)
{
    int k;
    int pivot = start;

    for(k = pivot; k <= end; k++) {
        if (arr[k] < arr[end]) {
            int temp = arr[k];
            arr[k] = arr[pivot];
            arr[pivot] = temp;
            pivot ++;
        } else {
          /* Nothing happens */  
        }
    }

    int temp = arr[pivot];
    arr[pivot] = arr[end];
    arr[end] = temp;

    return pivot;

}

void QuickSort(int arr[], int start, int end)
{
    if (start < end) {
            int pivot = FindPivot(arr, start, end);
            QuickSort(arr, start, pivot-1);
            QuickSort(arr, pivot+1, end);
    }
}

int main()
{
    int num;
    int k;

    printf("Welcome to Quick Sort algorithm..\n");
    printf("Enter number of elements..\n");

    scanf("%d", &num);

    for(k=0; k < num; k++) {
        scanf("%d", &arr[k]);
    }

    /* Quick Sort */
    QuickSort(arr, 0, num-1);

    for(k=0; k < num; k++) {
        printf("[%d]", arr[k]);
    }
}
