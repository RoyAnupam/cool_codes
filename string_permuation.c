#include <stdio.h>


void Perm(char *str, int posfixed, int len)
{
    if (posfixed == len) {
       printf("%s\n", str); 
        
    } else {
        int k;
        char c;

        for(k=posfixed; k < len; k++) {
            
            c = str[k];
            str[k] = str[posfixed];
            str[posfixed] = c;

            Perm(str, posfixed+1, len);

            c = str[k];
            str[k] = str[posfixed];
            str[posfixed] = c;
        }
    }

}

int main()
{
    printf("Welcome to string permutaion..\n");
    char str[5] = "abcd\0";

    Perm(str, 0, 4);

}
