#include <stdio.h>
#include <string.h>

#define MAX 1000

int HasSubstring(char *text, int textlen, char *pattern, int patlen, int arr[patlen])
{

    int i = 0; /* Index for Text: For start of sub-string */
    int j = 0; /* Index for Text: index to match with Pattern */
    int k = 0; /* Index for Pattern: index that is matched with Text */

    while(j < textlen && k <patlen) {
        if (text[j] == pattern[k]) {
            j++;
            k++;
        } else {
            printf("[%d][%d]\n", i, j);
            if (k!= 0) {
                k = arr[k-1];
                if (k == 0)
                    i = j;
                else
                    i = j-k;
            } else {
                j++;
                i++;
            }
        }
    }
    return i;
}

void CreatePrefixTable(char *pattern, int patlen, int arr[patlen])
{

    int i = 0;
    int j = 1;

    /* Initialize */
    arr[0] = 0;

    while(j < patlen) {
        if (pattern[j] == pattern[i]) {
            arr[j] = i +1;
            i++;
            j++;
        } else {
            if (i !=0) {
                i = arr[i-1];
                continue;
            }
            arr[j] = 0;
            j++;
        }
    }

/* Uncomment to test Prefix table 
    int k;
    for(k=0; k < patlen; k++) {
        printf("[%d]\n", arr[k]);
    }
*/

}

void RunKMP(char *text, char *pattern, int textlen, int patlen)
{
    int arr[patlen];

    CreatePrefixTable(pattern, patlen, arr);

    printf("Substring matched position [%d]\n", HasSubstring(text, textlen, pattern, patlen, arr));
}

int main()
{

    char text[MAX];
    char pattern[MAX];

    printf("Enter Text..\n");
    scanf("%s", text);

    printf("Enter Pattern..\n");
    scanf("%s", pattern);


    RunKMP(text, pattern, strlen(text), strlen(pattern));
}
