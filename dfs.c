#include <stdio.h>
#include <stdlib.h>

#define ROW 100
#define COL 100

#define GREY 100
#define WHITE -1

int matrix[ROW][COL];
int arr[ROW];
int num;

DFS(int node)
{
    int count = 0;
    printf("Node [%d]", node);
    arr[node] = GREY;

    for (; count <num; count++) {
        if (matrix[node][count] == 0)
            continue;
            if (arr[count] == WHITE)
                DFS(count);
    }

}

int main()
{
    int r, c, count;

    printf("Enter Number of nodes in your graph..");
    scanf("%d", &num);

    for (r=0; r < num; r++) {
        for (c = 0; c< num; c++) {
            scanf("%d", &matrix[r][c]);
        }
    }
    for (r=0; r < num; r++) {
        for (c = 0; c< num; c++) {
            printf("[%d]", matrix[r][c]);
        }
    
    }

    for (count =0; count < num; count++)
        arr[count] = WHITE;

    DFS(0);
}
