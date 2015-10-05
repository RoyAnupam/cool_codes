#include <stdio.h>

#define ROW 1000
#define COL 1000

#define VISITED 1
#define NOTVISITED 0
#define INF 999999

int matrix[ROW][COL];
int dist[ROW];
int visited[ROW];


int FindSmallestFromStart(int num, int arr[num][num], int *node)
{

    int smallestpath = 999999, c;

    for(c=0; c < num; c++) {
        if (visited[c] == NOTVISITED) {
            if (dist[c] <= smallestpath) {
                smallestpath = dist[c];
                *node = c;
            }
        }
    }

    return smallestpath;

}

void Dik(int arr[ROW][COL], int start, int num)
{
    /* Initialize the visisted and distance from source arrays to
       NOTVISITED and INF respectively */
    int c;
    for(c=0; c < num; c++) {
        dist[c] = INF;
        visited[c] = NOTVISITED;
    }

    /*Mark distance from source as 0*/
    dist[start] = 0;

    /* Find distance node which has smallest distance from start */
    int k;
    for (k=0; k <num; k++) {
        int node;
        int distance = FindSmallestFromStart(num, arr, &node);
        //printf("Smallest Node [%d]\n", node);
        visited[node] = VISITED;

        /*Check matrix for each path that exists from found node with smallest distance */
        for(c=0; c<num; c++) {
            /* If path exists */
            if (matrix[node][c] != 0) {
                /* If node is not visited */
                if (visited[c] == NOTVISITED) {
                    /* If current weigth is more than new weight, then update distance */
                    if (dist[c] > (dist[node] + matrix[node][c])) {
                        dist[c] = (dist[node]+matrix[node][c]);
                    }

                }
            }
        }

    }
}

int main()
{
    int num, r, c;
    printf("Welcome to Disktras algorithm concept...\n");
    printf("Enter number of nodes in weighted graph..\n");
    scanf("%d", &num);

    for(r=0; r <num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }

    for(r=0; r <num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", matrix[r][c]);
        }
        printf("\n");
    }

    Dik(matrix, 0, num);
    for (c=0; c< num; c++)
        printf("Dist [%d]\n", dist[c]);
    printf("\n");
}
