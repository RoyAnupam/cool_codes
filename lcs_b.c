#include <stdio.h>
#include <string.h>


int max(int r1, int r2)
{
    return (r1 > r2)? r1 : r2;
}

int lcs(char X[], char Y[], int x_m, int y_n)
{
    int r,c;

    int arr[x_m+1][y_n+1];

    /* Lets choose m as rows, y as cols*/
    for(r=0; r< x_m+1; r++)
        arr[r][0] = 0;

    for(c=0; c< y_n+1; c++)
        arr[0][c] = 0;


    for(r=1; r<x_m+1; r++) {
        for(c=1; c<y_n+1; c++) {
            if (X[r-1] == Y[c-1]) {
                arr[r][c] = arr[r][c-1]+1;
            } else{
                arr[r][c] = max(arr[r-1][c],arr[r][c-1]);
            }
        }
    }

    return arr[r-1][c-1];
}

int main()

{

    //char X[] = "AGGTAB";
    //char Y[] = "GXTXAYB";
    //char X[] = "AGGTAY";
    //char Y[] = "AGGTAB";

    char X[] = "ABCDGH";
    char Y[] = "AEDFHR";

    int m = strlen(X);

    int n = strlen(Y);

    printf("Length of LCS is %d\n", lcs( X, Y, m, n ) );

    return 0;

}
