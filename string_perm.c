#include <stdio.h>
#include <string.h>

#define MAX 1000


void swap(char *x, char*y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char* str, int startindex, int endindex, int strlen)
{
    if (strlen == 1) {
        printf("[%s]\n", str);
    }
    else {
        int c;
        for (c=0; c<strlen; c++) {
            /* Swap start with end */
            swap(str+startindex, str+ (startindex+c));
            //printf("\n startindex [%d] endindex[%d] strlen[%d]\n", startindex, endindex, strlen);
            permute(str, startindex+1, endindex, strlen-1);
            swap(str+startindex, str+ (startindex+c));
        }
    }

}

int main()
{
    char buf[MAX];
    int c;
    char ch1, ch2, ch3, ch4;

    scanf(" %c", &ch1);
    buf[0] = ch1;

    scanf(" %c", &ch2);
    buf[1] = ch2;

    scanf(" %c", &ch3);
    buf[2] = ch3;

    scanf(" %c", &ch4);
    buf[3] = ch4;
    printf("[%d] [%d] [%d] [%d]", buf[0], buf[1], buf[2], buf[3]);

    /*
    printf("Enter string to be permuted..\n");
    scanf("%s", buf);

    printf("Entered string is [%s]\n", buf);

    int n = strlen(buf);
    permute(buf, 0, n-1, n);
*/
    return 0;
}
