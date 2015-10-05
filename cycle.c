#include<stdio.h>
#include<stdlib.h>

/****Global Variables****/
int A[20][20],visited[20],count=0,n;
int seq[20],connected=1,acyclic=1;

/****DFS Function Declaration****/
void DFS();

/****DFSearch Function Declaration****/
void DFSearch(int cur);

/****Main Function****/
int main() 
{    
    int i,j;

    printf("\nEnter no of Vertices: ");
    scanf("%d",&n);

    printf("\nEnter the Adjacency Matrix(1/0):\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&A[i][j]);

    printf("\nThe Depth First Search Traversal:\n");

    DFS();

    for(i=1;i<=n;i++)
        printf("%c,%d\t",'a'+seq[i]-1,i);

    if(connected && acyclic)    printf("\n\nIt is a Connected, Acyclic Graph!");
    if(!connected && acyclic)   printf("\n\nIt is a Not-Connected, Acyclic Graph!");
    if(connected && !acyclic)   printf("\n\nGraph is a Connected, Cyclic Graph!");
    if(!connected && !acyclic)  printf("\n\nIt is a Not-Connected, Cyclic Graph!");

    printf("\n\n");
    return 0;
}

/****DFS Function Definition****/
void DFS()
{ 
    int i;
    for(i=1;i<=n;i++)
        if(!visited[i])
        {
            if(i>1) connected=0;
            DFSearch(i);    
        } 
}

/****DFSearch Function Definition****/
void DFSearch(int cur) 
{
    int i,j;
    visited[cur]=++count;

    seq[count]=cur; 
    for(i=1;i<count-1;i++)
        if(A[cur][seq[i]]) 
            acyclic=0;

    for(i=1;i<=n;i++)
        if(A[cur][i] && !visited[i])
            DFSearch(i);

}
