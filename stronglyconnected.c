#include <stdio.h>
#include <string.h>

#define MAX 100
int visited[MAX];
int mat[MAX][MAX];
int trans[MAX][MAX];
int num;


int Stack[MAX];
int f;
static int visitedcount;

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

void DFS(int startnode)
{
    int k;
    //printf("Node [%d]\n", startnode);

    for(k=0; k < num; k++) {
        if (mat[startnode][k] != 0 && visited[k] != 1) {
            visitedcount++;
            visited[k] = 1;
            DFS(k);
        }

    }
    printf("Pushing startnode[%d] to stack\n", startnode);
    push(startnode);

}

void DFS_rev(int startnode)
{
    int k;
    printf("Node [%d]\n", startnode);

    for(k=0; k < num; k++) {
        if (trans[startnode][k] != 0 && visited[k] != 1) {
            visitedcount++;
            visited[k] = 1;
            DFS_rev(k);
        }

    }
}

int main(void)
{
    int r, c, k, startnode;
    printf("Welcome to KosaRaju SCC algorithm..\n");
    printf("Enter number of nodes in Entire graph..\n");
    scanf("%d", &num);

    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
            trans[c][r] = mat[r][c];
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

    /* Transpose Graph */
    printf("\nTransposed Graph\n");
    printf("===============\n");
    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", trans[r][c]);
        }
        printf("\n");
    }
    printf("Transposing done!!!");
    /* Initially no nodes i visited */
    for(k=0; k < num; k++) {
        visited[k] = 0;
    }

    if (num-3 >=0)
        startnode = num-3;
    else
        startnode = 0;

    visitedcount = 1;
    visited[startnode] = 1;

    /* DFS1: Pick a arbitary node in Original Graph */
    while (visitedcount != num) {
        DFS(startnode);
        printf("DFS Finsished, visited count [%d]\n", visitedcount);
        for(k=0; k < num; k++) {
            if(visited[k] == 0) {
                startnode = k;
                printf("For next DFS, start node [%d]\n", startnode);
                visitedcount++;
                visited[k] = 1;
                break;
            }
        }
    }
    printf("DFS Done on Original Graph..\n");


    /* DFS2: On reverse graph */
    for(k=0; k < num; k++) {
        visited[k] = 0;
    }

    visitedcount = 0;
    int ssc_count = 0;

    while(!IsEmpty()) {
        int element = pop();
        if (visited[element] == 0) {
            visitedcount++;
            visited[element] = 1;
            ssc_count++;
            printf("\nSCC count [%d]..\n", ssc_count);
            DFS_rev(element);
            printf("\n");
        }
    }

}

