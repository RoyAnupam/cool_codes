#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
    int adj;
    int val_adj;
    struct node *nextadj;
};

typedef struct node adjlist;
int visited[MAX];

adjlist* arr[MAX];

void DFS(adjlist *startnode)
{

    while(startnode) {
        if (!visited[startnode->adj]) {
            printf("Node[%d]\n", startnode->adj);
            visited[startnode->adj] = 1;
            DFS(arr[startnode->adj]);
        }
        startnode = startnode->nextadj;
    }
}

int main()
{
    int r;
    int c;
    int num;
    int val;
    int k;
    adjlist *cur = NULL;

    printf("Welcome to cycle in Undirected graph..\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);

    for(k=0; k < num; k++) {
        visited[k] = 0;
        arr[k] = NULL;
    }

    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &val);
            if (val) {
                if (!arr[r]) {
                    arr[r] = (adjlist*)malloc(sizeof(adjlist));
                    arr[r]->adj = c;
                    arr[r]->val_adj = val;
                    arr[r]->nextadj = NULL;
                    cur = arr[r];
                    printf("@@Val of cur adj [%d]\n", cur->adj);
                } else {
                    cur->nextadj = (adjlist*)malloc(sizeof(adjlist));
                    cur->nextadj->adj = c;
                    cur->nextadj->val_adj = val;
                    cur = cur->nextadj;
                    cur->nextadj = NULL;
                    printf("##Val of cur adj [%d]\n", cur->adj);
                }
            }
        }
    } /* Input done */


    for(k=0; k < num; k++) {
        if (!visited[k]) {
            visited[k] = 1;
            printf("Node[%d]\n", k);
            DFS(arr[k]);
            printf("Check next\n");
        }

    }
}
