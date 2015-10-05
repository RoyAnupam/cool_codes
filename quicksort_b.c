#include <stdio.h>

int num;
int arr[100];

int partition(int arr[], int start, int end)
{

    int pivot = end;
    int pIndex = start;
    int k;
    int temp;

    for(k=start; k < end; k++) {
       if (arr[k] <= arr[pivot]) {
            int temp = arr[pIndex];
            arr[pIndex] = arr[k];
            arr[k] = temp;
            pIndex++;
       }
    }

    temp = arr[pivot];
    arr[pivot] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;

}

void QuickSort(int arr[], int start, int end)
{
    if (start < end) {
        int pIndex = partition(arr, start, end);
        QuickSort(arr, start, pIndex-1);
        QuickSort(arr, pIndex+1, end);
    }

}


int main()
{
    int k;
    printf("Welcome to Quick Sort...\n");
    printf("Enter no of nodes..\n");
    scanf("%d", &num);

    for(k=0; k < num; k++) {
        scanf("%d", &arr[k]);
    }

    QuickSort(arr, 0, num-1);

    for(k=0; k < num; k++)
        printf("[%d]", arr[k]);
}
