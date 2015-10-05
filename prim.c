#include <stdio.h>
#include <string.h>

#define MAX 1000
#define INF 0XFFFF

int matrix[MAX][MAX];

int num;
int t_elemeents;
int visited[MAX];
int parent[MAX];

int PickMinimum()
{
    int k;
    int minimum = INF;
    int l;
    int nextnode;

    for(k=0; k <num; k++) {
        if (visited[k]) {
            for(l=0; l <num; l++) {
                if (matrix[k][l] != 0 && visited[l] != 1) {
                    if (matrix[k][l] <= minimum) {
                        minimum = matrix[k][l];
                        parent[l] = k;
                        nextnode = l;
                    }
                }
            }
        }
    }
    if (minimum!= INF) {
        for (k=0; k <num;k++) {
            /* mark parents of all other non visited ndoes to INF */
            if (visited[k] == 0 && k != nextnode)
                parent[k] = INF;
        }
        /* Mark nextnode as visisted, means, it is enetered in Tree set now */
        printf("\n Minimum wiegth [%d] nextnode [%d] parent of next node[%d]\n", minimum, nextnode, parent[nextnode]);
        visited[nextnode] = 1;
        return nextnode;
    } else 
        return 0;

}

void printMST()
{
    int k;
    printf("Edge   Weight num [%d]\n", num);
    for (k= 0; k < num; k++) {
        if (parent[k] != INF) {
            printf("%d - %d    %d\n", parent[k], k, matrix[parent[k]][k]);
        }
    }

}

void PrimMST(void)
{
    int k;
    int t_elements = 0;

    /* Initialize*/
    for(k=0; k <num; k++) {
        visited[k] = 0;
        parent[k] = INF;
    }

    /* Start with 0th node of the graph i.e 0th node will become the root node of the tree */
    visited[0] = 1;
    parent[0] = INF; /* Root node of the tree will not have any parent */
    t_elements++;

    /* loop till tree set contains num nodes in it */
    /*for all the elements in tree set, pic node with smallest outgoing edge */ 
    for (k=0; k <num; k++) {
        int nextnode = PickMinimum();
        if (nextnode) {
            t_elements++;
            if (t_elements == num)
                break;
        }
    }
    printf("Number of elements in tree set [%d]\n", t_elements);
    if (t_elements)
        printMST();
    else
        printf("MST could not be generated out of the given graph...!!!");

}

int main()
{
    int r, j;
    printf("Welcome to Prims MST..\n");
    printf("Enter number of nodes..\n");
    scanf("%d", &num);

    for(r=0; r<num;r++) {
        for(j=0; j<num; j++) {
            scanf("%d", &matrix[r][j]);
        }
    }

    for(r=0; r<num;r++) {
        for(j=0; j<num; j++)
            printf("[%d]", matrix[r][j]);
        printf("\n"); 
    }
    PrimMST();
}
