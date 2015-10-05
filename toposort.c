#include <stdio.h>
#include <string.h>

#define MAX 100
int visited[MAX];
int mat[MAX][MAX];
int num;
#define WHITE 0
#define GREY 1
#define BLACK 2

int Stack[MAX];
int f;
static int visitedcount;
static int cyclednode;
static int cyclednodereached;
static int numcycle;

int cycle[MAX];

int IsFull(void)
{
    if (f == MAX-1) {
        printf("Stack is FULL..\n");
        return 1;
    }
    else
        return 0;
}

int IsEmpty(void)
{
    if (f == -1) {
        printf("Stack is Empty..\n");
        return 1;
    }
    else
        return 0;
}

int pop(void)
{
    if (IsEmpty()) {
        return -1;
    } else {
        int element = Stack[f];
        f--;
        return element;
    }
}

void push(int element)
{
    if (IsFull()) {
        return;
    } else {
        Stack[++f] = element;
    }
}

int TopoSort(int startnode)
{
    int k;

    for(k=0; k < num; k++) {
        if (mat[startnode][k] != 0 && visited[k] == WHITE) {
            visitedcount++;
            visited[k] = GREY;
            if (TopoSort(k)) {

            } else {
                if (visited[startnode] == GREY) {
                    if (startnode == cyclednode) {
                        cycle[++numcycle] = startnode;
                        cyclednodereached = 1;
                    }

                    if (cyclednodereached == 0)
                        cycle[++numcycle] = startnode;
                }

                return 0;
            }

        } else if (mat[startnode][k] != 0 && visited[k] == GREY){
            printf("Oops!! Loop detected while sorting, TopoSort not possible..\n", k);
            cyclednode = k;
            cycle[++numcycle] = k;
            cycle[++numcycle] = startnode;
            return 0;
        }
    }
    //printf("Pushing startnode[%d] to stack and mark Black\n", startnode);
    visited[startnode] = BLACK;
    push(startnode);
    return 1;

}

void PrintJobs(void)
{
    printf("TopoSort Done, print jobs in decreasing order of their finish time\n");
    printf("\n");
    while(!IsEmpty()) {
        printf("Node [%d]\n", pop());
    }

}

void PrintCycle()
{
    while(numcycle >=0) {
        printf("[%d]", cycle[numcycle]);
        numcycle--;
    }

}

int main(void)
{
    int r, c, k, startnode;
    printf("Welcome to Topological Sort Algorithm..\n");
    printf("Enter number of nodes in Entire graph..\n");
    scanf("%d", &num);

    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    printf("Original graph\n");
    printf("===============\n");
    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", mat[r][c]);
        }
        printf("\n");
    }

    /* Initialize first node */
    f = -1;
    for(k=0; k < num; k++) {
        visited[k] = WHITE;
        cycle[k] = -1;
    }

    numcycle = -1;
    visitedcount = 1;

    for(k= 0; k < num; k++){
        if (visited[k] == WHITE) {
            visited[k] = GREY;
            if (TopoSort(k)) {
            } else {
                printf("Cycle detected.. print the cycle\n");
                break;
            }
        }
    }
    if (numcycle>=0)
        PrintCycle();
    else
        PrintJobs();

}

