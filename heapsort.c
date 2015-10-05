#include <stdio.h>

#define MAX 1000

int num;
int arr[MAX];

void MaxHeapify(int list[], int index, int heapsize)
{

    int parent = list[index];
    int leftchild = list[index*2];
    int rightchild = list[index*2 +1];
    int largest = index; //that means, parent index is set to largest first

    /* Find larger between parent and leftchild */
    if (index*2 <= heapsize && leftchild > list[largest])
        largest = index*2;

    /* Find larger between larger from last operation and right child */
    if ((index*2+1) <= heapsize && rightchild > list[largest])
        largest = index*2 + 1;

    /* Parent is not largest any more that means, left or rightchild is larger */
    if (largest != index) {
        /* Swap parent and whichever is largest */
        int temp = parent;
        if (largest == index*2) {
            list[index] = list[index*2];
            list[index*2] = temp;
            MaxHeapify(list, index*2, heapsize);
        } else {
            list[index] = list[index*2+1];
            list[index*2+1] = temp;
            MaxHeapify(list, index*2+1, heapsize);
        }
    }
}

void BuildMaxHeap(int list[], int heapsize)
{
    int k;

    for (k= (heapsize/2); k >=1; k--) {
        MaxHeapify(list, k, heapsize);    
    }

}

void HeapSort(int list[], int num)
{
    int k;

    int heapsize = num;

    /* Create Max-Heap */
    BuildMaxHeap(list, heapsize);
    printf("After build heap, lets check...\n"); 
    for(k=1; k <= num; k++)
        printf("[%d]", arr[k]);
    printf("\n");

    /* Until heapsize is 1, Swap root node of Max heap with last child and call Max-Heap*/

    while(heapsize >1){
        /*Swap */
       int temp = list[1];
       list[1] = list[heapsize];
       list[heapsize] = temp;
       heapsize--;
       MaxHeapify(list, 1, heapsize);      
    }

}


int main()
{
    int k;

    printf("Welcome to HeapSort Implementation...\n");
    printf("Enter number of nodes...\n");
    scanf("%d", &num);

    for(k=1; k <= num; k++)
        scanf("%d", &arr[k]);

    HeapSort(arr, num);


    for(k=1; k <= num; k++)
        printf("[%d]", arr[k]);

}
