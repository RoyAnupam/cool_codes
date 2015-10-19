#include <stdio.h>
#define MAX 1000

int arr[MAX];
int graph[MAX][MAX];
int color[MAX*MAX];
int num;

int f = -1;
int r = -1;

int DeQ()
{
    int element;

    if (IsQEmpty())
        return;

    element = arr[f];

    if (f==r) {
        f = -1;
        r = -1;
    } else {
        f++;
    }
    return element;
}

void EnQ(int element)
{
    if(IsQFull())
        return;

    if (f ==-1)
        f = 0;

    if (r == MAX-1) {
        r = 0;
    } else
        r++;

    arr[r] = element;
}

int IsQEmpty()
{
    if (f == -1)
        return 1;
    else
        return 0;
}

int IsQFull()
{

    if (f == 0 && r == MAX-1 || f-r ==1)
        return 1;
    else
        return 0;
}

int IsSafe(int row, int col)
{

    if (row>=0 && row <= num-1 && col >=0 && col <=num-1)
        return 1;
    else
        return 0;

}
/*
void BFS(void)
{

    while(!IsQEmpty()) {

        int adj;
        int startnode = DeQ();

        //Compute row, col back from point
        int row = startnode/num;
        int col = startnode % num;

        color[startnode] = 3;
        printf("@@@@Startnode = %d\n", startnode);

        int x_cor[8] = {0,0,-1,1,-1,1,1,-1};
        int y_cor[8] = {1,-1,0,0,1,-1,1,-1};

        // Check all adjacent nodes of startnode //
        for(adj = 0; adj < 8; adj++) {

            int adj_x = row+ x_cor[adj];
            int adj_y = col+ y_cor[adj];

            if (IsSafe(adj_x, adj_y) && graph[adj_x][adj_y] && color[adj_x*num+adj_y] == 1) {

                color[adj_x*num + adj_y] = 2;
                printf("Enqueuing [%d]\n", adj_x*num + adj_y);
                EnQ(adj_x*num + adj_y);
            }
        }
    }
}
*/
void BFS(void)
{

    while(!IsQEmpty()) {

        int adj;
        int startnode = DeQ();

        printf("@@@@Startnode = %d\n", startnode);
        //Compute row, col back from point
        int row = startnode/num;
        int col = startnode % num;

        int x_cor[8] = {0,0,-1,1,-1,1,1,-1};
        int y_cor[8] = {1,-1,0,0,1,-1,1,-1};

        // Check all adjacent nodes of startnode //
        for(adj = 0; adj < 8; adj++) {

            int adj_x = row+ x_cor[adj];
            int adj_y = col+ y_cor[adj];

            if (IsSafe(adj_x, adj_y) && graph[adj_x][adj_y] == 1) {

                graph[adj_x][adj_y] = 2;
                printf("Enqueuing [%d]\n", adj_x*num + adj_y);
                EnQ(adj_x*num + adj_y);
            }
        }
    }
}

int main()
{
    int r;
    int c;
    int k;
    int connectedcomponent = 0;

    printf("Welcome to finding Islands..(Undirected graph)..\n");
    printf("Enter number of vertices...\n");
    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &graph[r][c]);
        }
    }

/*

    for(k=0; k < num*num; k++) {
        color[k] = 1;
    }

    for(r=0; r < num; r++) {

        for(c=0; c < num; c++) {

            if (graph[r][c]) {
                int point = r*num +c;

                if (color[point] == 1) { //White

                    color[point] = 2; // Grey
                    EnQ(point);
                    connectedcomponent +=1;
                    BFS();
                    printf("###BFS end..\n");
                }
            }
        }
    }
*/
    for(r=0; r < num; r++) {

        for(c=0; c < num; c++) {

            if (graph[r][c]) {

                if (graph[r][c] == 1) { // Not Visited
                    graph[r][c] = 2; // Visited
                    int point = r*num +c;
                    EnQ(point);
                    connectedcomponent +=1;
                    BFS();
                    printf("###BFS end..\n");
                }
            }
        }
    }
    printf("Number of islands or connected components is [%d]\n", connectedcomponent);
}
