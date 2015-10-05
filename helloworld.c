#include <stdio.h>
#include <string.h>

int main () {

    int *p;

    printf("Anupam Roy");

    if (5) {
        printf("Oh goood\n");
        
        p = (int*)malloc(sizeof(int)*10);
        p[0] = 19;
        p[1] = 43;
        printf("First byte [%d] second byte [%d]", p[0], p[1]);
    } else {
        printf("jgfdjfdshfjhh");

    }
    free(p);
}
