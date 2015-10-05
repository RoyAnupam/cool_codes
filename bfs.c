#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define MAX 100
#define MAX_ROW 1000
#define MAX_COL 1000
#define true 1
#define false 0
#define bool int
#define VISITED 1

int array[SIZE];
int s, e;

int matrix[MAX_ROW][MAX_COL];

int arr[MAX];
void EnQ(int val)
{
    if (IsQFull())
        printf("\nCant enter val [%d], coz Q is FULL", val);
    else {
        if (s == MAX) {
            s = 0;
            arr[s] = val;
            //printf("\nEnqueued [%d]\n", val);
            s++;
        } else {
            arr[s] = val;
            s++;
            //printf("\nEnqueued [%d]\n", val);
        }
    }
}

int DeQ(void)
{

    if (IsQEmpty()) {
        printf("\nCant dequeue coz Q is Emplty");
        return -100;
    }

    if (e == MAX-1) {
        int temp = arr[e];
        e = -1;
        if (s == MAX)
            s = 0;
        //printf("\nDequeued [%d]\n", temp);
        return temp;
    } /*else if (e == -1){
        e = 1;
        return arr[0];
        } */else {
            int temp = arr[e];
            e++;
            //printf("\nDequeued [%d]\n", temp);
            return temp;
        }
}

bool IsQEmpty()
{
    if ((e == -1 && s == 0) || (((s-e) == 1) && (s != MAX))) {
        return true;
    } else {
        return false;
    }
}

bool IsQFull()
{
    if ((s == MAX && e == -1) || (e == s)) {
        return true;
    } else {
        return false;
    }

}

#if 0
int CQ[SIZE],f=-1,r=-1;       /* Global declarations */

EnQ(int elem)
{                       /* Function for Insert operation */
    if( IsQFull()) printf("\n\n Overflow!!!!\n\n");
    else
    {
        if(f==-1)f=0;
        r=(r+1) % SIZE;
        CQ[r]=elem;
    }
}

int DeQ()
{                      /* Function for Delete operation */
    int elem;
    if(IsQEmpty()){ printf("\n\nUnderflow!!!!\n\n");
        return(-1); }
    else
    {
        elem=CQ[f];
        if(f==r){ f=-1; r=-1;} /* Q has only one element ? */
        else
            f=(f+1) % SIZE;
        return(elem);
    }
}

int  IsQFull()
{                     /* Function to Check Circular Queue Full */
    if( (f==r+1) || (f == 0 && r== SIZE-1)) return 1;
    return 0;
}

int IsQEmpty()
{                    /* Function to Check Circular Queue Empty */
    if(f== -1) return 1;
    return 0;
}
#endif

BFS(int node, int num)
{
    int c;
    array[node] = VISITED;
    EnQ(node);
    //printf("\nFirst Enqueued val [%d]\n", node);

    while(!IsQEmpty()) {

        int val = DeQ();
        printf("\n Dequeued val[%d] ", val);

        for(c=0; c < num; c++) {
            if (matrix[val][c] != 0 && array[c] != VISITED) {
                array[c] = VISITED;
                EnQ(c);
                //printf("\nEnqueued val [%d]\n", c);
            }
        }
    }
}

int main()
{
    /*Initialize start and end pointers */
    int row, col, num;

    memset(matrix, 0, MAX_ROW+ MAX_COL);
    printf("Enter number of ndoes in Graph \n");
    scanf("%d", &num);

    for (row=0; row < num; row++) {
        for(col=0; col <num; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    for (row=0; row < num; row++) {
        for(col=0; col <num; col++) {
            printf("[%d]", matrix[row][col]);
        }
        printf("\n");
    }

    memset(array, 0, sizeof(array));
    BFS(0, num);

}
