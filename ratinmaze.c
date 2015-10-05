#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int maze[MAX][MAX];
int num;

int IsMoveSafe(int x, int y, int x_moves[], int y_moves[])
{
    if (x <0 || x > num-1)
        return 0;

    if (y <0 || y > num-1)
        return 0;

    if (maze[x][y] == 0)
        return 0;

    return 1;
}


int MoveRat(int x, int y, int x_moves[], int y_moves[])
{
    int k;

    if (x == num-1 && y == num-1)
        return 1; //destination reached

    for(k=0; k <2; k++) {

        int next_x = x + x_moves[k];
        int next_y = y + y_moves[k];

        if (IsMoveSafe(next_x, next_y, x_moves, y_moves)) {
    
            printf("@@Next safe move [%d][%d]\n", next_x, next_y);
            maze[next_x][next_y] = 2;

            if (MoveRat(next_x, next_y, x_moves, y_moves)) {
                return 1;
            } else {
                maze[next_x][next_y] = 1;// BackTrack

            }

        }
    }
        return 0;

}


int main()
{

    int r, c;

    printf("Welcome to Rat in a Maze problem..\n");
    printf("Enter number of rows or cols in the maze..\n");
    scanf("%d", &num);

    for(r=0; r<num; r++) {
        for(c=0; c<num;c++)
            scanf("%d", &maze[r][c]);
    }

    for(r=0; r<num; r++) {
        for(c=0; c<num;c++)
            printf("[%d]", maze[r][c]);
            printf("\n");
    }

    int x_moves[2] = {0, 1};
    int y_moves[2] = {1, 0};

    maze[0][0] = 2;
    
    if (MoveRat(0,0, x_moves, y_moves)) {
        printf("Solution exists, now print Maze..\n");
        for(r=0; r<num; r++) {
            for(c=0; c<num;c++)
                printf("[%d]", maze[r][c]);
            printf("\n");
        }

    } else {
        printf("Sorry!!!!Solution Does not exists..\n");
    }
}

