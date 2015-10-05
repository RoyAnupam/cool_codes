#include <stdio.h>
int array[100];
int num;

void Combine(int arr[], int left[], int right[], int totalsize, int leftsize, int rightsize)
{

    int k = 0;  // <===for left
    int l = 0;  // <===for right
    int m = 0;  // <===for main array

    while(k < leftsize && l < rightsize) {
        if (left[k] <= right[l]) {
            arr[m] = left[k];
            k++;
            m++;
        } else if (left[k] >= right[l]) {
            arr[m] = right[l];
            l++;
            m++;
        }
    }

    while(m < totalsize && k != leftsize) {
        arr[m] = left[k];
        m++;
        k++;
    }

    while(m < totalsize && l != rightsize) {
        arr[m] = right[l];
        m++;
        l++;
    }
}

void MergeSort(int arr[], int sizeofarr)
{

    if (sizeofarr == 1)
        return;

    int k, l;

    int mid = sizeofarr/2;

    /* Create two auxillary arrays */
    int left[mid];
    int right[sizeofarr - mid];

    /*Fill left array */
    for(k=0; k < mid;k++)
        left[k] = arr[k];

    /*Fill left array */
    for(k=mid, l=0; k < sizeofarr; k++, l++)
        right[l] = arr[k];

    MergeSort(left, mid);
    MergeSort(right, sizeofarr - mid);
    Combine(arr, left, right, sizeofarr, mid, sizeofarr-mid);
}

int main()
{
    int k;

    printf("Welcome to Merge sorting..\n");
    printf("Enter numbver of elements,,\n");
    scanf("%d", &num);

    for(k=0; k < num; k++)
        scanf("%d", &array[k]);

    MergeSort(array, num);
    for(k=0; k < num; k++)
        printf("[%d]", array[k]);


}
