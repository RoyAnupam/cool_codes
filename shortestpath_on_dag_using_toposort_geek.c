#include <stdio.h>
#define MAX 1000
#define INF 99999

int graph[MAX][MAX];
int visited[MAX];
int distance[MAX];
int stack[MAX];
int stackptr = -1;
int num;

int pop(void)
{
    int k;

    if (IsStackEmpty())
        return -1;
    else {

        int element = stack[stackptr];
        stackptr -= 1;
        return element;
    }
}

void push(int element)
{
    if (IsStackFull())
        return;
    else {
        stackptr += 1;
        stack[stackptr] = element;
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

int peek(void)
{
    return stack[stackptr];

}

void UpdateDistanceFromSource(void)
{
    int adj;
    int k;

    while(!IsStackEmpty()) {
        int startnode = pop();
        if (startnode ==0)
            continue;

        for (adj=0; adj < num; adj++) {
            if (graph[startnode][adj] != INF) {
                printf("Adjacent of %d is %d\n", startnode, adj);
                if (distance[startnode] + graph[startnode][adj] < distance[adj])
                    distance[adj] = distance[startnode] + graph[startnode][adj];
            }
        }
    }
}

void DoTopoSortOnGraph(int startnode)
{
    int adj;

    for(adj=0; adj < num; adj++) {

        if (graph[startnode][adj] && graph[startnode][adj] != INF && !visited[adj]){
            visited[adj] = 1;
            DoTopoSortOnGraph(adj);
        }
    }
    /* Finished exploring all adjacent vertices of startnode */
    //printf("Pushing startnode [%d] to Stack\n", startnode);
    push(startnode);
}

int main()
{
    int r;
    int c;
    int k;

    printf(" Welcome to single source shortest path on DAG using toposort..\n");
    printf("Enter number of nodes in DAG..\n");

    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &graph[r][c]);
        }
    }

    for(k=0; k < num; k++) {
        visited[k] = 0;
    }   

    int startnode = 0;

    /* Topological Sorting */
    DoTopoSortOnGraph(startnode);

    /* Start finding shortest path */
    for(k=0; k < num; k++) {
        distance[k] = INF;
    }

    distance[1] = 0;
    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            //printf("[%d]", graph[r][c]);
        }
        //printf("\n");
    }
    UpdateDistanceFromSource();

    for(k=0; k < num; k++)
        printf("Distance from start node to %d = [%d]\n", k, distance[k]);
}
