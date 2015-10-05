#include <stdio.h>
#define MAX 1000
#define RED 100
#define BLUE 200

int mat[MAX][MAX];
int color[MAX];

int f = -1;
int r = -1;

int arr[MAX];
int num;

void EnQ(int val)
{
    if (IsFull()) {
        return ;
    } else {
        if (r==MAX-1) {
            r= 0;
            arr[r] = val;
        } else {
            arr[++r] = val;
        }
        if (f==-1)
            f = 0;
    }
}

int DeQ()
{
    if (IsEmpty())
        return -1;
    else {
        int val;
        val = arr[f];

        if (f == r) {
            f = -1;
            r = -1;
        } else {
            val = arr[f];
            f++;
        }
        return val;
    }
}

int IsEmpty()
{
    if (f == -1)
        return 1;
    else
        return 0;
}

int IsFull()
{
    if ((f-r) == 1 || (f==0 && r == MAX-1)) {
        return 1;
    } else
        return 0;
}

int oppositecolor(int color)
{
    if (color == RED)
        return BLUE;
    else
        return RED;
}

int BFS(int node)
{
    int k;

    for(k=0; k <num; k++)
        color[k] = -1;

    color[node] = RED;
    EnQ(node);

    while(!IsEmpty()) {
        int cwn = DeQ();
        printf("Node [%d]", cwn);

        for (k=0; k < num; k++) {
            if (mat[cwn][k] != 0) {

                if (color[k] == -1) {
                    color[k] = oppositecolor(color[cwn]);
                    EnQ(k);
                } else if ( color[k] == color[cwn]) {
                    printf("Got a node [%d] coloured same with parent, Graph is not Bipartite..\n", k);
                    return 0;
                } else if (color[k] != color[cwn]){
                    /* Already visited node */
                }
            }
        }
    }
    return 1;
}

int main()
{
    int r;
    int c;

    printf("Welcome to Bapartite graph find..\n");
    printf("Enter number of elements in the graph..\n");

    scanf("%d", &num);

    for(r=0; r < num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    int bipart = BFS(0);
    printf("Graph is Bipartite [%d]", bipart);

}
