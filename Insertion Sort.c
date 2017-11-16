#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void InsertionSort(int n);
int list[1100];

int main(void)
{
    int i, n;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d", &list[i]);

        InsertionSort(n);

        for(i=0;i<n;i++)
            printf("%d ", list[i]);
        printf("\n");
    }

    return 0;
}

void InsertionSort(int n)
{
    int key, i, j;

    for(j=1;j<n;j++)
    {
        i=j-1;
        key=list[j];

        while(key<list[i])
        {
            list[i+1]=list[i];
            i--;
        }
        list[i+1]=key;
    }
}
