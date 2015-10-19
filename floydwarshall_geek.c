#if 0
#include<stdio.h>

#define V 4

#define INF 99999

void printSolution(int dist[][V]);


void printSolution(int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");

    int i;
    int j;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshell (int graph[][V])
{
    int dist[V][V], i, j, k;

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist);
}


// driver program to test above function
int main()
{
    /* Let us create the following weighted graph
       10
       (0)------->(3)
       |         /|\
       5 |          |
       |          | 1
       \|/         |
       (1)------->(2)
       3           */
    int graph[V][V] = { {0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    // Print the solution
    floydWarshell(graph);
    return 0;
}

#endif



//#if 0
#include <stdio.h>
#define MAX 1000
int arr[MAX][MAX];
int dist[MAX][MAX];

int main()
{

    int num;
    int i;
    int j;
    int k;
    int r;
    int c;

    printf("Welcome to Floyd Warshall..\n");
    printf("Enter number of ndoes..\n");
    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &dist[r][c]);
        }
    }

    for(k=0; k < num; k++) {
        for(i=0; i < num; i++) {
            for(j=0; j < num; j++) {
                if ((dist[i][k] + dist[k][j]) < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            /*
            if (dist[i][j] == 9999)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
                */
                printf("[%d]", dist[i][j]);
        }
        printf("\n");
    }

}
//#endif
