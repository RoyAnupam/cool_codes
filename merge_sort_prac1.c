#include <stdio.h>
#define MAX 1000

int arr[MAX];
int num;

void Merge(int arr[], int leftarr[], int rightarr[], int num,
                int leftarrsize, int rightarrsize)
{
    int k = 0; /* Left*/
    int l = 0; /* Right */
    int m = 0; /* Main arr */

    /* Swap */
    while(k < leftarrsize && l < rightarrsize && m < num) {

        if (leftarr[k] < rightarr[l]) {
            arr[m] = leftarr[k];
            m++;
            k++;
        } else {
            arr[m] = rightarr[l];
            m++;
            l++;
        }
    }

    while(k < leftarrsize) {
        arr[m] = leftarr[k];
        k++;
        m++;
    }

    while(l < rightarrsize) {
        arr[m] = rightarr[l];
        l++;
        m++;
    }
}

void MergeSort(int arr[], /*int start, int end,*/ int num)
{

    if (num != 1) {

        int z;
        int k, l=0, m = 0;
        int mid = num/2;

        int leftarr[mid];
        int rightarr[num - mid];

        for(k=0; k <mid; k++) {
            leftarr[l] = arr[k];
            l++;
        }

        for(k=mid; k <num; k++) {
            rightarr[m] = arr[k];
            m++;
        }

        MergeSort(leftarr, /*start, start+mid -1,*/ mid);
        MergeSort(rightarr, /*start + (end-start)/2, end,*/ num-mid);
        Merge(arr, leftarr, rightarr, num, mid, num-mid);
    }

}


int main()
{
    int k;

    printf("Welcome to Merge Sort algorithm...\n");
    printf("Enter number of elements in Array..\n");

    scanf("%d", &num);

    for(k=0; k < num; k++) {
        scanf("%d", &arr[k]);
    }

    MergeSort(arr, /*0, num-1,*/ num);

    for(k=0; k < num; k++) {
        printf("[%d]", arr[k]);
    }
}
