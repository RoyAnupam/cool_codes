#include <stdio.h>
#include <stdlib.h>

#define MAX 6
#define true 1
#define false 0
#define bool int

int arr[MAX];
int s, e;


void EnQ(int val)
{
    if (IsQFull())
        printf("Cant enter val [%d], coz Q is FULL", val);
    else {
        if (s == MAX) {
            s = 0;
            arr[s] = val;
            s++;
        } else {
            arr[s] = val;
            s++;
        }
    }
}

int DeQ(void)
{

    if (IsQEmpty()) {
        printf("Cant dequeue coz Q is Emplty");
        return -100;
    }

    if (e == MAX-1) {
        int temp = arr[e];
        e = -1;
        if (s == MAX)
            s = 0;
        return temp;
    } else if (e == -1){
        e = 1;
        return arr[0];
    } else {
        int temp = arr[e];
        e++;
        return temp;
    }
}

bool IsQEmpty()
{
    if ((e == -1 && s == 0) || (((s-e) == 1) && (s != MAX))) {
        return true;
    } else {
        return false;
    }
}

bool IsQFull()
{
    if ((s == MAX && e == -1) || (e == s)) {
        return true;
    } else {
        return false;
    }

}

int main()
{
    /*Initialize start and end pointers */
    s = 0;
    e = -1;

    int val;

    printf("Q Empty status [%d]\n", IsQEmpty());
    printf("Q Full status [%d]\n", IsQFull());
    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("\nQ Empty status [%d]\n", IsQEmpty());
    printf("Q Full status [%d]\n", IsQFull());

    printf("\n DeQueued val [%d]", DeQ());
    printf("\n DeQueued val [%d]", DeQ());
    printf("\n DeQueued val [%d]", DeQ());
    //printf("\n DeQueued val [%d]", DeQ());
    //printf("\n DeQueued val [%d]", DeQ());
    //printf("\n DeQueued val [%d]", DeQ());

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("Enter Item to be queued\n");
    scanf("%d", &val);
    EnQ(val);

    printf("\n DeQueued val [%d]", DeQ());
    printf("\nQ Empty status [%d]\n", IsQEmpty());
    printf("Q Full status [%d]\n", IsQFull());
}
