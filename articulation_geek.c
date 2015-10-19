#include <stdio.h>
#define MAX 1000

int arr[MAX][MAX];
int lowtime[MAX];
int arrivaltime[MAX];
int visited[MAX];
int parent[MAX];
int time = 0;
int num;

void FindArticulationPoint(startnode)
{
    int adj;
    int childnode = 0;
    int articulationpoint = 0;

    for(adj=0; adj < num; adj++) {

        if (parent[startnode] == adj)
            continue;
        else {

            if ( arr[startnode][adj] && visited[adj] == 0) {
                arrivaltime[adj] = ++time;
                lowtime[adj] = arrivaltime[adj];
                visited[adj] = 1;
                childnode += 1;
                parent[adj] = startnode;
                FindArticulationPoint(adj);
                /* All child nodes are explored and backtracking done to startnode
                   Check if the adj node's lowtime is less than or equal to my low time */
                if (lowtime[adj] > arrivaltime[startnode]) {
                    articulationpoint = 1;
                } else if (lowtime[adj] < arrivaltime[startnode]) {
                    lowtime[startnode] = lowtime[adj];
                    //printf("Startnode is not an articulation point\n");

                }
            } else if ( arr[startnode][adj] && visited[adj]) {
                /* Found a back edge from startnode -> adj */
                if (arrivaltime[startnode] > arrivaltime[adj]) {
                    lowtime[startnode] = arrivaltime[adj];
                }
            }
        }
    } /* All adjacent nodes of startnode are explored, time to return back to its parent
         Before returning back, just check if this node is an articulation point */
    if ((arrivaltime[startnode] == 1 && childnode == 2) || (arrivaltime[startnode] != 1 && articulationpoint == 1)) {
        printf("Node [%d] is an articulation point\n", startnode);
    }
}


int main()
{
    int k;
    int r;
    int c;

    printf("Welcome to Articulation point..\n");
    printf("Enter number of nodes in the graph..\n");
    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &arr[r][c]);
        }
    }

    for(k=0; k < num; k++) {
        visited[k] = 0;
    }

    /* Initialization */
    int startnode = 0;
    parent[startnode] = -1;
    visited[startnode] = 1;
    arrivaltime[startnode] = ++time;
    lowtime[startnode] = arrivaltime[startnode];

    FindArticulationPoint(startnode);

#if 0
    for(k=0; k < num; k++) {
        printf("Arrival of %d = %d & lowtime of %d = %d\n", k, arrivaltime[k], k, lowtime[k]);
    }
#endif


}
