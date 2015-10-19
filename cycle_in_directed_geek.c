#include <stdio.h>
#define MAX 1000
#define INF 99999

int graph[MAX][MAX];
int num;
int parent[MAX];
int visited[MAX];

void PrintCycle(int startnode, int cyclestart)
{
    while(parent[


}

int DFS(int startnode)
{
    int adj;

    for(adj=0; adj < num; adj++) {
        if (graph[startnode][adj] == INF)
            continue;

        if (!visited[adj]) {
            printf("Adjacent node [%d], parent[%d] \n", adj, startnode);
            visited[adj] = 1;
            parent[adj] = startnode;
            if (DFS(adj) == -1)
                return -1;
        } else if (visited[adj]) {
            /* Found a cycle */
            printf("Found a cycle.. startnode %d adj %d\n", startnode, adj);
            PrintCycle(startnode, adj);
            return -1;
        }
    }
    return 1;
}

int main()
{
    int r;
    int c;
    int k;
    int result;

    printf("Welcome to find Cycle in Directed graph..\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);

    for(r=0; r< num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &graph[r][c]);
        }
    }

    for(k=0; k< num; k++) {
        visited[k] = 0;
        parent[k] = -1;
    }

    for (k=0; k < num; k++) {

        if (visited[k] == 0) {
            visited[k] = 1;
            int result = DFS(k);
            printf("Result [%d]\n", result);
        }

        if(result)
            continue;
        }
    }
}
