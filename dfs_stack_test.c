#include <stdio.h>
#define MAX 1000

int mat[MAX][MAX];
int visited[MAX];
int parent[MAX];


int num;


void DFS(int startnode)
{
    int k;
    printf("Node is [%d]\n", startnode);

    for(k=0; k < num; k++){
        if (mat[startnode][k] !=0 && visited[k] ==0) {
            visited[k] = 1;
            parent[k] = startnode;
            DFS(k);
        } else if (mat[startnode][k] !=0 && visited[k] == 1 && parent[startnode] != k) {
            printf("Cycle is detected...startnode[%d] ancestor [%d]\n", startnode, k);
            return;
        }
    }


}


int main(void)
{
    int r, c, k;

    printf("Welcome to DFS traversal..\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);

    for(r=0; r< num; r++) {
        for (c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    visited[2] = 1;
    parent[2] = 2;
    DFS(2);

}
