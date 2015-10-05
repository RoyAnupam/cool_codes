#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define true 1
#define false 0

int mat[MAX][MAX];
int pos[MAX];

int Absolute(int x1, int x2)
{
    int absx1;

    if (x1 > x2)
        absx1 = x1-x2;
    else
        absx1 = x2 - x1;

    return absx1;

}

int IsSafe(int row, int col, int num)
{

    int r;
    /* Check if element exist in col */
    for(r=0; r < num; r++) {
        if (pos[r] == col)
            return false;
    }
    /* Check if element exist in diagonal */
    for (r=0; r < num; r++) {
        if (pos[r] != -1) {
            if (Absolute(r, row) == Absolute(pos[r], col)) 
                return false;
        }
    }
    return true;
}

void NQueen(int row, int num)
{

    int r, c, k;

    for (c=0; c < num; c++) {
        if (pos[num-1] != -1)
            return;
            /* Initialize the row to no Queen before checking safeness
             If we dont reset the position, then it will create problem
             during backtracking. As Queens are already placed in oldeer
             loops, and it will hinder in placing queens in new positions */
            pos[row] = -1;
            if (IsSafe(row, c, num)) {
                printf("Safe pos [%d][%d]\n", row, c);
                pos[row] = c;
                if (row+1 == num) {
                    for (k=0; k < num; k++)
                        printf("%dth Row pos [%d][%d]\n", k, k, pos[k]);
                }
                else
                    NQueen(row+1, num);
            }
            /* if in any partuclar row, if no suitable coloumn
            is found, then we have to backtrack to previous row,
            but before that just reset pos of current row, because
            this row will started fresh again from start*/
            if (c== num-1 && pos[num-1] != -1)
                pos[row] = -1;
    }
}

int main()
{
    int num, r, c;
    printf("Welcome to N-Queen problem..\n");
    printf("Enter nxn val..\n");
    scanf("%d", &num);

    for (r=0; r<num; r++) {
        for(c=0; c<num; c++) {
            mat[r][c] = 0;
        }
    }

    /* Initialize position array */
    for (r=0; r<num; r++)
        pos[r] = -1;

    NQueen(0, num);

}

