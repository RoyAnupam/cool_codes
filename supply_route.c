#include <stdio.h>
#include <time.h>
#define MAX 200
#define MAXNODES 40000
#define INF 999999
#define NO 0
#define YES 1

int inputmat[MAX][MAX];
int adjlist[MAXNODES][4];

/* Dij Data structures */
int dist[MAXNODES];
int visited[MAXNODES];


int IsSafe(int x, int y, int num)
{
    if (x >=0 && x<= num-1 && y >= 0 && y <= num-1)
        return 1;
    else
        return 0;
}

void CreateGraph(int num)
{

    int r;
    int c;
    int k;

    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};

    for(r=0; r< num; r++) {
        for(c=0; c<num; c++) {
            int l = 0;
            for(k=0; k < 4; k++) {
                if (IsSafe(r+x[k], c+y[k], num)) {
                    int val = num*(r+x[k]) + (c+y[k]);
                    //printf("indexx[%d] indexy[%d] val[%d]\n", r*num+c, l, val);
                    adjlist[r*num+c][l] = val;
                    l++;
                }
            }
        }
    }
#if 0
    /* Print Adjacency List */
    for(r=0; r< num*num; r++) {
        for(c=0; c< 4; c++) {
            printf("[%d]", adjlist[r][c]);
        }
        printf("\n");
    }
#endif
}

int FindMin(int num)
{
    int k;
    int smallestdist = INF;
    int smallestnode = 0;


    for(k=0; k < num*num; k++) {
        //printf("node [%d]  distcance [%d] visited[%d]\n", k, dist[k], visited[k]);
        if (dist[k] <= smallestdist && visited[k] == NO) {
            smallestdist = dist[k];
            smallestnode = k;
        }
    }

    return smallestnode;
}

int distancetodestination(int destination, int num)
{
    return inputmat[destination/num][destination%num];

}

void ShortestPath(int num)
{
    int k;
    int adj;

    for(k=0; k < num*num; k++) {
        int startnode = FindMin(num);
        //printf("Start node[%d]\n", startnode);
        visited[startnode] = YES;

        for(adj =0; adj <4; adj++) {
            if (adjlist[startnode][adj] != -1 && visited[adjlist[startnode][adj]] == NO) {
                int distancetoadj = distancetodestination(adjlist[startnode][adj], num);
                if (distancetoadj + dist[startnode]  < dist[adjlist[startnode][adj]])
                    dist[adjlist[startnode][adj]] = distancetoadj + dist[startnode];
            }
        }

    }

}

int main()
{
    printf("Welcome to Supply route problem..\n");

    int testcase;
    int T;

    scanf("%d", &T);

    for(testcase=1; testcase <=T; testcase++) {

        int num;
        int r;
        int c;
        int ans;
        char ch;
        int k;
        /*
        time_t start, stop;
        clock_t ticks; long count;
        time(&start);*/

        clock_t start, stop;
        start = clock();

        scanf("%d", &num);

        /* Initialize Adjacency List */
        for(r=0; r< num*num; r++) {
            for(c=0; c<4; c++) {
                adjlist[r][c] = -1;
            }

        }

        for(r=0; r< num; r++) {
            for(c=0; c< num; c++) {
                scanf(" %c", &ch);
                inputmat[r][c] = ch - '0';
            }
        }

#if 0
        for(r=0; r< num; r++) {
            for(c=0; c< num; c++) {
                printf("[%d]", inputmat[r][c]);
            }
            printf("\n");
        }
#endif

        CreateGraph(num);


        /* Diktra preparation */
        for(k=0; k < num*num; k++) {
            dist[k] = INF;
            visited[k] = NO;
        }
        dist[0] = 0;
        ShortestPath(num);

        ans = dist[num*num -1];
        printf("#%d %d\n", testcase, ans);

        stop = clock(); 
        //time(&stop);
        printf("testcase [%d] started %6.3f seconds Finished %6.3f \n", testcase, start, stop /*difftime(stop, start)*/);

    }

}
