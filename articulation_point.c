#include <stdio.h>
#define MAX 1000
#define FALSE 0
#define TRUE 1
#define YES 1
#define NO 0
#define NIL -100

int mat[MAX][MAX];
int articulationset[MAX];
int parent[MAX];
int lowtime[MAX];
int visittime[MAX];
int visited[MAX];
int totalvisittime;

int num;

void DFS(int startnode)
{
    int adj;
    int articulation = FALSE;
    int childcount = 0;


    //printf("Node[%d]", startnode);

    for(adj=0; adj < num; adj++) {

        /* If parent, then continue */
        if (parent[startnode] == adj)
            continue;

        /* If no path exists */
        if (mat[startnode][adj] == 0)
            continue;


        if (mat[startnode][adj] !=0) {

            /* Tree Edge*/
            if (visited[adj] == NO) {
                
                childcount++;
                
                visited[adj] = YES;
                totalvisittime++;

                visittime[adj] = totalvisittime;
                lowtime[adj] = totalvisittime;

                parent[adj] = startnode;
                DFS(adj);

                if (visittime[startnode] <= lowtime[adj]) {
                    printf("Found one articulation point [%d] adj node [%d] childcount [%d] \n", startnode, adj, childcount);
                    articulation = YES;
                } else if (lowtime[startnode] > lowtime[adj]) {
                    lowtime[startnode] = lowtime[adj];
                }

            } else {
                /* Found a back edge, update low time */
                if (visittime[startnode] >= visittime[adj])
                        lowtime[startnode] = visittime[adj];
            } 
        } /* Path exists between startnode and adj node */
    } /* Finished processing the startnode */


    if (parent[startnode] == NIL && childcount == 2) {
        articulationset[startnode] = TRUE;
    } else if (parent[startnode] != NIL && articulation == YES) {
        articulationset[startnode] = TRUE;
    }

}


int main()
{
    int r;
    int c;
    int startnode;

    printf("Welcome to Articulation point finding Algorithm..\n");
    printf("Enter number of the vertices you want in the graph...\n");
    scanf("%d", &num);

    for(r=0; r<num; r++){
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    printf("Enter Startnode ..\n");
    scanf("%d", &startnode);

    for(r=0; r<num; r++) {
        visited[r] = NO;
        parent[r] = NIL;
        articulationset[r] = FALSE;
        lowtime[r] = -1;
        visittime[r] = -1;
    }

    totalvisittime = 0;
    visited[startnode] = YES;
    lowtime[startnode] = 0;
    visittime[startnode] = 0;
    DFS(startnode);

    for(r=0; r< num; r++)
        printf("Artculation: [%d]\n", articulationset[r]);

}

