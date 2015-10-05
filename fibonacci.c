#include <stdio.h>

int fib(int n)
{

    if(n<=2)
        return 1;

    else {
        int f = 0;
        int i = 0;
        int j = 1;
        int k;

        for(k=3; k <=n; k++) {
            f = i+j;
            i = j;
            j = f;
        }
        return f;
    }

}

int main()
{
    int n;
    printf("Enter n..\n");
    scanf("%d", &n);
    if (n==1)
        printf("[%d]", n-1);
    else    
        printf("[%d]",fib(n));
}
