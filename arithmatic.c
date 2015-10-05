#if 0
#include <stdio.h>


int main(void)
{
    int arr[] = {2, 3, 4, 5, 6};

    printf("Size of arra [%d]", sizeof(arr));
    int mod = 2/5;
    printf("Mod is [%d]\n", mod);
}


#include <stdio.h>
#include <math.h>

double power(double x, double y)
{
    double result=0;

    if (y==0)
        return 1;
    else {
        result = x*power(x, y-1);    
        return result;
    }

}

/* power method implementation in C */
int main(){

    int number[8] = {1,0,0,0,1,0,1,0}, result = 0, x;

    int elements = sizeof(number)/sizeof(int);
    int num = elements-1;
    x=0;

    while(num >=0) {
        result += (power(2,x)* number[num]);
        num--;
        x++;
    }

    printf("Final result: %d\n", result);

    return 0;

}
#endif
#include <stdio.h>
//#include <stdlib.h>

int main()
{

    /*
       int x = -90;
       printf("Absolute value of x is [%d] real value [%d]", abs(x), x);
       char dest[10];
       char *src = "My name is Anupam";

       strncpy(dest, src, 6);
       printf("Destination [%s] strlen [%d]", dest, strlen(dest));

       int n=0;
       while(dest[n]!= '\0') {
       printf(" %c %d", dest[n], n);
       n++;
       }
     */

    /*
       char test;
       char ch;
       scanf("%c", &test);
       scanf(" %c", &ch);
       printf("[%c]\n", test);
       printf("[%c]", ch);
     */

    /*
       int i, ii;
       char str1[20], str2[30], ch;
       float f;

       char input[] = "25 45.6 Thompson f";
       sscanf(input, "%d %f %s %c", &i, &f, str1, &ch);
       printf("[%d] [%f] [%s][%c]", i, f, str1, ch);
     */

/*    
       char *str1 = "1236abb";
       char str2[] = {'3', '6', '7', '9', 'a', 'b'};
       int num, num1;


       sscanf(str1, "%d", &num);
       printf("[%d]", num);

       sscanf(str2, "%d", &num1);
       printf("[%d]", num1);
*/   

    /*
       char str[10]; // MUST be big enough to hold all the characters of your number!!

       printf("15 in binary is %s\n",  itoa(15, str, 2));
       printf("15 in octal is %s\n",   itoa(15, str, 8));
       printf("15 in decimal is %s\n", itoa(15, str, 10));
       printf("15 in hex is %s\n",     itoa(15, str, 16));
     */


    //atoi
    int num;
    char *str = "1234ab";
    printf("[%d]", atoi(str));


    char str1[20];
    int i; float num1=5456.567;
    i = sprintf(str1, "%f", num1);
    printf("15 in decimal is %s\n", str1);
    printf("sprintf returns: %d and strlen is [%d]\n\n", i, strlen(str1));

}

