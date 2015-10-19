#include <stdio.h>
#define MAX 500
int arr[MAX];

int f = -1;
int r = -1;

EnQ(int element)
{
    if (IsQFull())
        return;

    if (f == -1) {
        f = 0;
    }
    if (r == MAX-1)
        r = 0;
    else
        r++;
    arr[r] = element;
}

int DeQ()
{
    if (IsQEmpty())
        return;

    int element = arr[f];
    if (f==r) {
        f = -1;
        r = -1;
    } else
        f++;

    return element;
}

int IsQEmpty()
{
    if (f == -1)
        return 1;
    else
        return 0;

}

int IsQFull()
{
    if (f-r == 1 || (f == 0 && r == MAX-1))
        return 1;
    else
        return 0;

}

int main()
{


}
