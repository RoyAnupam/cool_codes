#include <stdio.h>
#define MAX 1000
#define INF 99999

int graph[MAX][MAX];
int num;
int stackptr = -1;
int stack[MAX];
int distance[MAX];
int visited[MAX];

int peek()
{
    return stack[stackptr];
}

int Push(int element)
{
    if(IsStackFull())
        return;
    else {
        stackptr += 1;
        stack[stackptr] = element;
    }
}

int Pop(void)
{
    if(IsStackEmpty())
        return -1;
    else {
        int element;
        element = stack[stackptr];
        stackptr -= 1;
        return element;
    }
}

int IsStackEmpty(void)
{
    if (stackptr == -1)
        return 1;
    else
        return 0;
}

int IsStackFull(void)
{
    if (stackptr == MAX-1)
        return 1;
    else
        return 0;
}

void DoTopologicalSortOnGraph(int startnode)
{
    int adj;

    for(adj = 0; adj < num; adj++) {

        if (graph[startnode][adj] != INF && !visited[adj]) {
            visited[adj] = 1;
            DoTopologicalSortOnGraph(adj);
        }
    }
    /* Done exploring all children of startnode */
    Push(startnode);
}

void UpdateDistances(int source)
{
    int k;
    int adj;

    int node = Pop();

    /* Keep popping till we find the source */
    while(source != node) {
        node = Pop();
    }

    Push(node);

    while(!IsStackEmpty()) {
            node = Pop();
        for(adj = 0; adj < num; adj++) {
            if (graph[node][adj] == INF)
                continue;

            if (distance[adj] == INF) {
                distance[adj] = distance[node] + graph[node][adj];
            } else if (distance[adj] < graph[node][adj] + distance[node] ) {
                distance[adj] = graph[node][adj] + distance[node];
            }
        }
    }
}

int main()
{
    int r;
    int c;
    int k;

    printf("Welcome to find Longest path on DAG..uisng toposort..\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);

    for(r=0; r< num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &graph[r][c]);
        }
    }

    for(k=0; k< num; k++)
        visited[k] = 0;

    int startnode = 0;
    visited[startnode] = 1;
    DoTopologicalSortOnGraph(startnode);

    printf("Topological sorting Done..\n");
    for(k=0; k < num; k++)
        distance[k] = INF;

    int source = 1;
    distance[source] = 0;
    UpdateDistances(source);

    for(k=0; k < num; k++)
        printf("Distance from source %d to %d = [%d]\n", source, k, distance[k]);
}
