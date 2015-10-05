#include <stdio.h>
#define MAX 1000


int num;
int arr[MAX];

int partition(int arr[], int start, int end)

{
    int pIndex;
    int k = start;

    int pivot = end;
    pIndex = start;

    while(k < end) {

        if (arr[k] <= arr[pivot]) {
            int temp = arr[pIndex];
            arr[pIndex] = arr[k];
            arr[k] = temp;
            pIndex++;
        }
        k++;
    }

    int temp = arr[pIndex];
    arr[pIndex] = arr[pivot];
    arr[pivot] = temp;
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

    printf("Welcome to Quick Sort algorithms...\n");
    printf("Enter number of elements in the list...\n");
    scanf("%d", &num);


    for(k=0; k < num; k++)
        scanf("%d", &arr[k]);

    QuickSort(arr, 0, num-1);

    printf("\n");

    for(k=0; k < num; k++)
        printf("[%d]", arr[k]);

}
