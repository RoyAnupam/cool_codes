#include <stdio.h>

#define MAX 1000
#define INF 99999

int visited[MAX];
int mat[MAX][MAX];
int distancefromsource[MAX];
int num;

int FindMinDistFromSource(void)
{
    int k;
    int mincost = -1;
    int node = 0;

    for(k = 0; k < num; k++) {
        if (visited[k] == 0) {
            if (distancefromsource[k] < mincost || mincost == -1) {
                mincost = distancefromsource[k];
                node = k;
            }
        }
    }

    return node;
}

void dik(int startnode)
{
    int i;
    int k;

    for(i=0; i < num; i++) {


        int node = FindMinDistFromSource();
        printf("Shortest node [%d]\n", node);
        visited[node] = 1;

        for(k=0; k < num; k++) {
            if (mat[node][k] != 0 && visited[k] == 0) {
                if ( distancefromsource[node] + mat[node][k] < distancefromsource[k]) {
                    distancefromsource[k] = distancefromsource[node] + mat[node][k];
                }
            }
        }


    }

}

int main(void)
{
    int r, c, k;

    printf("Welcome to dik algo..\n");
    printf("Enter no of nodes in the graph..\n");

    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    for(r=0; r < num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", mat[r][c]);
        }
        printf("\n");
    }

    for(r=0; r < num; r++) {
        visited[r] = 0;
        distancefromsource[r] = INF;
    }

    int startnode = 0;
    distancefromsource[0] = 0;

    dik(startnode);

    printf("Time to print solution...\n");
    for(k=0; k < num; k++)
        printf(" [%d] [%d]\n", k, distancefromsource[k]);


}
