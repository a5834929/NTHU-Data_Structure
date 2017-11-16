#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void mergesort(int array[], int start, int end);
void merge(int array[], int start, int end, int mid);

int c[20000];

int main(void)
{
    int i, a[20];

    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w+", stdout);

    for(i=0;i<20;i++)
        scanf("%d", &a[i]);

    mergesort(a, 0, 19);

    for(i=0;i<19;i++)
            printf("%d ", a[i]);

    printf("%d\n", a[i]);

    return 0;
}

void mergesort(int array[], int start, int end)
{
    int mid;

    if(end>start)
    {
        mid=(start+end)/2;
        mergesort(array, start, mid);
        mergesort(array, mid+1, end);
        merge(array, start, mid, end);
    }

    else
        return;
}

void merge(int array[], int start, int mid, int end)
{
    int i,j,k;

    i=k=start;
    j=mid+1;

    while(i<=mid && j<=end)
    {
        if(array[i]<=array[j])
        {
            c[k]=array[i];
            i++;
            k++;
        }

        else
        {
            c[k]=array[j];
            j++;
            k++;
        }
    }

    while(i<=mid && j>end)
    {
        c[k]=array[i];
        i++;
        k++;
    }

    while(j<=end && i>mid)
    {
        c[k]=array[j];
        j++;
        k++;
    }

    for(i=start;i<k;i++)
        array[i]=c[i];

    return;
}
