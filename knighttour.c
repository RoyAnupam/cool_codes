#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 

int mat[MAX][MAX];
int num;


int IsSafe(int row, int col)
{
    if (row <0 || row >num-1)
        return 0;
    if (col < 0 || col > num-1)
        return 0;

    if (mat[row][col] == -1)
        return 1;
    else
        return 0;

}

int KnightTour(int moves, int row, int col , int x_moves[], int y_moves[])
{
    int r, c, k;

    if (moves == num*num)
        return 1;

    for (k=0; k<8; k++) {

         int next_x = row + x_moves[k];
         int next_y = col + y_moves[k];

        if (IsSafe(next_x, next_y)) {
            
            mat[next_x][next_y] = moves;
            if (KnightTour(moves+1, next_x, next_y,x_moves, y_moves) == 1)
                return 1;
            else
                mat[next_x][next_y]= -1;
        }
    }
    return 0;
}


int main() 
{
    int r, c;
    printf("Welcome to Knight's Tour..\n");
    printf("Enter chess board configuration..");

    scanf("%d", &num);

    for(r=0; r <num; r++) {
        for(c=0; c<num; c++) {
            mat[r][c] = -1;
        }
    }

    int x_moves[8] = {2, 2, -2, -2, -1, 1, -1, 1};
    int y_moves[8] = {1, -1, 1, -1, 2, 2 -2, -2};

    mat[0][0] = 0;
    if (KnightTour(1,0, 0, x_moves, y_moves) == 1) {
        printf("\n Time to print Chess Board Now...\n\n...\n");

        for(r=0; r <num; r++) {
            for(c=0; c<num; c++) {
                printf("[%d]", mat[r][c]);
            }
            printf("\n");
        }
    }

}
#endif

//#if 0
#include <stdio.h>
#define N 8
#define bool int
#define true 1
#define false 0


int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[],
        int yMove[]);

/* A utility function to check if i,j are valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    if ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1)
        return 1;
    return 0;
}

/* A utility function to print solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    int x, y;
    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
            printf(" %2d ", sol[x][y]);
        printf("\n");
    }
}

/* This function solves the Knight Tour problem using Backtracking.  This
   function mainly uses solveKTUtil() to solve the problem. It returns false if
   no complete tour is possible, otherwise return true and prints the tour.
   Please note that there may be more than one solutions, this function
   prints one of the feasible solutions.  */
bool solveKT()
{
    int sol[N][N], x, y;

    /* Initialization of solution matrix */
    for (x = 0; x < N; x++)
        for (y = 0; y < N; y++)
            sol[x][y] = -1;

    /* xMove[] and yMove[] define next move of Knight.
       xMove[] is for next value of x coordinate
       yMove[] is for next value of y coordinate */
    //int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    //int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    int xMove[8] = {2, 2, -2, -2, -1, 1, -1, 1};
    int yMove[8] = {1, -1, 1, -1, 2, 2 -2, -2};
    // Since the Knight is initially at the first block
    sol[0][0]  = 0;

    /* Start from 0,0 and explore all tours using solveKTUtil() */
    if(solveKTUtil(0, 0, 1, sol, xMove, yMove) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    else
        printSolution(sol);

    return true;
}

/* A recursive utility function to solve Knight Tour problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N],
        int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N*N)
        return true;

    /* Try all next moves from the current coordinate x, y */
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == true)
                return true;
            else
                sol[next_x][next_y] = -1;// backtracking
        }
    }

    return false;
}

/* Driver program to test above functions */
int main()
{
    solveKT();
    getchar();
    return 0;
}
//#endif
