#include <stdio.h>
#define MAX 1000
#define INF 99999

int arr[MAX][MAX];

int FindMinKey(int num, int MSTSet[], int key[])
{
    int k;
    int min = INF;
    int minnode;

    for(k=0; k < num; k++) {
        if (!MSTSet[k] && key[k] < min) {
            min = key[k];
            minnode = k;
        }
    }
    return minnode;
}

int main()
{
    int key[MAX];
    int MSTSet[MAX];
    int parent[MAX];
    int k;
    int num;
    int r;
    int c;
    int l;

    printf("Welcome to PRIM's shortest path algo..");
    printf("Enter number of elements..\n");
    scanf("%d", &num);

    for(r=0; r< num; r++) {
        for(c=0; c< num; c++) {
            scanf("%d", &arr[r][c]);
        }
    }

    for(r=0; r< num; r++) {
        for(c=0; c< num; c++) {
            printf("[%d]", arr[r][c]);
        }
        printf("\n");
    }

    for(k=0; k < num; k++) {
        parent[k] = INF;
        key[k] = INF;
        MSTSet[k] = 0;
    }

    /* Initialize key 0*/
    key[0] = 0;
    parent[0] = -1;


    for(k=0; k < num; k++) {

        int minkey = FindMinKey(num, MSTSet, key);

        /* Include Minkey in MST set*/
        MSTSet[minkey] = 1;

        for(l=0; l < num; l++) {

            if (arr[minkey][l] && !MSTSet[l]) {

                if (arr[minkey][l] < key[l]) {
                    key[l] = arr[minkey][l];
                    parent[l] = minkey;
                }
            }
        }

    }

    printf("Parent    child\n");
    printf("===============\n");
    /* Print MST */
    for(k=1; k< num; k++) {

        printf("[%d]   [%d]   [%d]\n", parent[k], k, arr[parent[k]][k]);

    }


    return 0;
}
