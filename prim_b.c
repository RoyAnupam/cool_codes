#include <stdio.h>

#define MAX 100
#define INF 99999
int mat[MAX][MAX];
int parent[MAX];
int num;


int IsMST_Full()
{
    int k;
    for(k=0; k < num; k++) {
        if (parent[k] == INF)
            return 0;
    }
    return 1;
}

int IsVertexInMST(int vertex)
{

    if(parent[vertex] != INF)
        return 1;
    else
        return 0;

}

int main()
{
    int r, c, k, l, i;
    printf("Welcome to Prims's..\n");
    printf("Enter number of nodes..\n");

    scanf("%d", &num);

    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            scanf("%d", &mat[r][c]);
        }
    }

    for(r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            printf("[%d]", mat[r][c]);
        }
        printf("\n");
    }

    for(i=0; i < num; i++) {
        parent[i] = INF;
    }

    parent[0] = 0;

    while(!IsMST_Full()) {

        int mincost = 0;
        int parentnode;
        int childnode;

        for(k=0; k < num; k++) {
            
            if (IsVertexInMST(k)) {

                for(l=0; l < num; l++) {

                    if(mat[k][l] !=0 && !IsVertexInMST(l)) {
                        if (mat[k][l] < mincost || mincost ==0) {
                            mincost = mat[k][l];
                            childnode = l;
                            parentnode = k;
                        }
                    }
                }
            }

        }
        printf("%d %d\n", childnode, parentnode);
        parent[childnode] = parentnode;
    }

    printf(" Edge        Wight\n");
    printf("====================\n");
    for(k=0; k < num; k++)
        printf("%d  %d --> %d\n", parent[k], k, mat[parent[k]][k]);
}
