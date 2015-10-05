#include <stdio.h>
#define MAX 1000

int arr[MAX];

void InsertionSort(int num, int arr[num])
{
    int k;
    int l;
    int pos;

    for (k=1; k < num; k++) {

        int tobematched = arr[k];
        pos = k;

        for(l=k-1; l >= 0; l--) {
            if (tobematched < arr[l]) {
                arr[pos] = arr[l];
                pos--;
            }
        }
        arr[pos] = tobematched;
    }
}

int main()
{
    int num;
    int k;

    printf("Welcome to Insertion sort algorithm..\n");
    printf("Enter number of elements..\n");

    scanf("%d", &num);

    for(k=0; k < num; k++) {
        scanf("%d", &arr[k]);
    }
    InsertionSort(num, arr);

    for(k=0; k < num; k++) {
        printf("[%d]", arr[k]);
    }
}
