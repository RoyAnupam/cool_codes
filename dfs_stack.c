#include <stdio.h>
#include <stdlib.h>

#define MAX 100

#define ROW 100
#define COL 100

int matrix[ROW][COL];
int visited[ROW];
int num;

int Stack[MAX];
int f;

int pop(void)
{
    if (IsStackEmpty())
        return -1;
    else {
        int element = Stack[f];
        f--;
        return element;
    }

}

void push(int element)
{
    if(IsStackFull())
        return;
    else {
        Stack[++f] = element;
    }

}

int IsStackEmpty(void)
{
    if (f==-1)
        return 1;
    else
        return 0;

}

int IsStackFull(void)
{
    if (f == MAX-1)
        return 1;
    else return 0;

}

int peek(void)
{
    return Stack[f];

}

/*
DFS(int node)
{
    int count = 0;
    printf("Node [%d]", node);
    arr[node] = GREY;

    for (; count <num; count++) {
        if (matrix[node][count] == 0)
            continue;
        if (arr[count] == WHITE)
            DFS(count);
    }

}
*/

void DFS()
{

    while(!IsStackEmpty()) {

        int element = peek();

        int k;

        int childfound = 0;
        for(k=0; k < num; k++) {
            if (matrix[element][k] == 1 && visited[k] != 1) {
                    visited[k] = 1;
                    printf("Element [%d]\n", k);
                    push(k);
                    childfound = 1;
                    break;
            }
        }
        if (!childfound)
            pop();
    }
}

int main()
{
    int r, c, count;
    f = -1;


    printf("Enter Number of nodes in your graph..");
    scanf("%d", &num);

    for (r=0; r < num; r++) {
        for (c = 0; c< num; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }
    for (r=0; r < num; r++) {
        for (c = 0; c< num; c++) {
            printf("[%d]", matrix[r][c]);
        }
        printf("\n");

    }

    for (count =0; count < num; count++)
        visited[count] = 0;

    push(0);
    visited[0] = 1;
    DFS();
}
