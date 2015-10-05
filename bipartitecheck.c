#include <stdio.h>
#include <stdlib.h>
#define MAX 100

#define RED 100
#define BLACK 200
#define NOTCOLORED 300

int f, r;
int Q[MAX];
int mat[MAX][MAX];
int num;
int color[MAX];


int IsQEmpty()
{
    if (f == -1) {
        return 1;
    } else
        return 0;
}

int IsQFull()
{
    if (f == 0 && r == MAX-1) {
        return 1;
    }

    if (f == r+1)
        return 1;

    return 0;
}

void EnQ(int element)
{
    if(IsQFull()) {
        return;
    }

    /* Enque element */
    if (f == -1)
        f = 0;
    if (r==MAX-1) {
        r = 0;
        Q[r] = element;
    } else {
        r++;
        Q[r] = element;
    }

}

int DeQ()
{
    if(IsQEmpty()) {
        return -1;
    }

    /* DeQueue element */
    int element = Q[f];

    if (f==r){ /* Only one element in Q */
        f = r = -1;
    } else {
        f++;
    }
    return element;
}

char *whichcolor(int colorcode)
{
    switch(colorcode) {
        case 100:
            return "RED";
        case 200:
            return "BLACK";
    }

}

int opposite(int color_code)
{   
    if(color_code == RED)
        return BLACK;
    if(color_code == BLACK)
        return RED;
}

int IsGraphBipartite(void)
{

    /* Start with node 0 of the graph as root node of BFS Tree */
    if (num >0) {
        /* Colour the first node or 0th node and EnQ it */
        color[0] = RED;
        EnQ(0);
    }

    while (!IsQEmpty()) {

        int k;
        /* DeQ one element and make it currently working Node */
        int cwn = DeQ();
        printf("Dequeued value is [%d] color[%d]\n", cwn, color[cwn]);
        if (IsQEmpty()) {
            printf(" Q is empty...\n");
        }


        /* Check each neighbouring node of currently working node and try color it opposite to currently working node*/
        for(k=0; k <num; k++) {
            if (mat[cwn][k]) {
                if (color[k] == color[cwn]) {
                    printf("Got an vertex [%d] from [%d] which is already coloured [%s]\n", k, cwn, whichcolor(color[k])); 
                    printf("Currently working node colour is also [%s]\n", whichcolor(color[cwn]));
                    return 0;
                } else  if (color[k] == NOTCOLORED) {
                    /* Color the adjacent node and Enqueue it */
                    color[k] = opposite(color[cwn]);
                    /* EnQ all the neightbouring nodes to Q */
                    EnQ(k);
                }
            }
        }

    }
    return 1;
}

int main()
{

    r = -1; /* Initialize */
    f = -1;
    int r, c, k;

    printf("Welcome to Bipartite check for the given graph...\n");
    printf("Enter number of ndoes in the graph..\n");
    scanf("%d", &num);

    for(r=0; r<num;r++) {
        for(c=0; c<num;c++)
            scanf("%d", &mat[r][c]);
    }

    for(r=0; r<num;r++) {
        for(c=0; c<num;c++)
            printf("[%d]", mat[r][c]);
        printf("\n");
    }

     /* First of all, un-color all the nodes */
     for(k=0; k < num; k++)
         color[k] = NOTCOLORED;

    if (IsGraphBipartite()) {
        printf("Graph is bipartite..\n");
    } else {
        printf("Graph is NOT Bipartite..\n");
    }
}

