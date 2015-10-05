#include <stdio.h>

#define MAX 1000
#define INF 0xFFFF

int mat[MAX][MAX];
int num;
int dist[MAX];
int parent[MAX];


void BellManFord(void)
{
    int i, k, l;

    for(l=1; l < num; l++) { /* Num -1 vertices */
        for(i=0; i < num; i++) { /* Each node */
            for(k=0; k < num; k++) { /* Check each outward edge from node i*/
                if (mat[i][k] != 0) { /* k is an outward edge */
                    if (dist[k] > dist[i] + mat[i][k]) {
                        dist[k] = dist[i] + mat[i][k];
                        //parent[k] = i;
                    }
                }
            }

        }
    }
}


void PrintShortestPath()
{
    int k;
    printf("Lests print shortest paths from 0th vertex now..\n");

    for(k=0; k < num; k++) {
        printf("Path from [0th] to [%dth] cost = [%d]\n", k, dist[k]);
    }

}

int main()
{
    int r, c, k;
    printf("Welcome to BellMan Ford Algorithm...\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);
    for(r=0; r < num; r ++)
        for(c=0; c < num; c++)
            scanf("%d", &mat[r][c]);

    for(r=0; r < num; r ++) {
        for(c=0; c < num; c++)
            printf("[%d]", mat[r][c]);
        printf("\n");
    }

    /* Initialize parent and distance vectors */
    for(k=0; k < num; k++) {
        dist[k] = INF;
        parent[k] = -1;
    }

    dist[0] = 0;
    parent[0] = 0;
    BellManFord();
    PrintShortestPath();
}

