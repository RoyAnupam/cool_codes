#include <stdio.h>

#define MAX 1000

int mat[MAX][MAX];
int visited[MAX];
int num;

static int totalcost;
static int startcity;

int final[MAX];
int temp[MAX];
int parent[MAX];

static int visitcount;
static int tempcost;

void DFS(int startnode)
{
    int k;
    for(k=0; k< num; k++) {
        if (mat[startnode][k] != 0 && visited[k] ==0) {
            tempcost += mat[startnode][k];
            visited[k] = 1;
            temp[++visitcount] = k;
            parent[k] = startnode;
            DFS(k);
        }
    }

    /**/
    if (visitcount == num-1) {
        tempcost += mat[startnode][startcity];
        printf("Finished a hamiltonian cycle, current cost = [%d]\n", tempcost);

        for(k=0; k < num; k++)
            printf("[%d]",  temp[k]);
        printf("\n");

        if (tempcost < totalcost || totalcost ==0) {
            totalcost = tempcost;
            for(k=0; k < num; k++)
                final[k] = temp[k];
        }
        visitcount--;
        visited[startnode] = 0;
        tempcost -= mat[startnode][startcity];
        tempcost -= mat[parent[startnode]][startnode];
    } else {
        visitcount--;
        visited[startnode] = 0;
        tempcost -= mat[parent[startnode]][startnode];
    }


}

int main()
{
    int r, c, k;
    printf("Welcome to Trvelling Salesman problem...\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);


    for(r=0; r< num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
    for(r=0; r< num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", mat[r][c]);
        }
        printf("\n");
    }
    for(k=0; k < num; k++)
        visited[k] = 0;

    startcity = 0;
    visited[0] = 1;
    totalcost = 0;
    tempcost = 0;
    visitcount = 0;
    temp[visitcount] = 0;
    DFS(0);

    printf("Minimum cost [%d]\n", totalcost);

    for(k=0; k < num; k++)
        printf("[%d]", final[k]);
    printf("\n");

}
