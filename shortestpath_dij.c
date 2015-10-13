#include <stdio.h>
#include <stdlib.h>
#define NO 0
#define YES 1 
#define MAX 1000
#define INF 999999

struct node {
    int adj_node;
    int adj_node_val;
    struct node *next_adjacent;
} node;

typedef struct node NODE;

NODE *arr[MAX];
int dist[MAX];
int visited[MAX];


int returnMin(int num)
{
    int k;

    int min = INF;
    int minnode = 0;

    for(k=0; k <num; k++) {
        if (dist[k] < min && visited[k] == NO) {
            min = dist[k];
            minnode = k;
        }
    }
    return minnode;
}

void dik(int num)
{
    int node;

    for(node=0; node < num; node++) {
        int min = returnMin(num);
        printf("Min node [%d]\n", min);

        NODE *startnode = arr[min];
        visited[min] = YES;

        while (startnode) {
            if (visited[startnode->adj_node] == NO) {
                if (dist[startnode->adj_node] > startnode->adj_node_val + dist[min]) 
                    dist[startnode->adj_node] = startnode->adj_node_val + dist[min];
            }
            startnode = startnode->next_adjacent;
        }
    }
}


int main()
{
    int r;
    int c;
    int val;
    NODE *cur = NULL;
    int k;
    int num;

    printf("Welcome to dij algorithm..\n");
    printf("Enter number of nodes in the graph..\n");

    scanf("%d", &num);

    /* Initialize distance and visited arrays */
    for(k=0; k < num; k++) {
        visited[k] = NO;
        dist[k] = INF;
        arr[k] = NULL;
    }

    for(r=0; r< num; r++) {
        for(c=0; c<num;c++) {
            scanf("%d", &val);
            if (val) {
                /**/
                if (!arr[r]) {
                    arr[r] = (NODE*) malloc(sizeof(NODE));
                    arr[r]->adj_node = c;
                    arr[r]->adj_node_val = val;
                    arr[r]->next_adjacent = NULL;
                    cur = arr[r];
                } else {
                    cur->next_adjacent = (NODE*) malloc(sizeof(NODE));
                    cur->next_adjacent->adj_node = c;
                    cur->next_adjacent->adj_node_val = val;
                    cur->next_adjacent->next_adjacent = NULL;
                    cur = cur->next_adjacent;
                }

            }
        }
    }
    int startnode = 0;
    dist[startnode] = 0;
    dik(num);

    for(k=0; k <num; k++) {
        printf("Distance from 0 to %d is [%d]\n", k, dist[k]);
    }
    printf("Anupam...exit...");
}
