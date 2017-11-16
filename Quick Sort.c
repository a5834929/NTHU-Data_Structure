#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void QuickSort(int left, int right);
int list[1100];

int main(void)
{
    int i, n;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d", &list[i]);

        QuickSort(0, n-1);

        for(i=0;i<n;i++)
            printf("%d ", list[i]);
        printf("\n");
    }

    return 0;
}

void QuickSort(int left, int right)
{
    int pivot, tmp, i, j;

    if(left<right)
    {
        pivot=list[left];
        i=left+1;
        j=right;

        while(i<=j)
        {
            while(list[i]<pivot && i<right)
                i++;
            while(list[j]>pivot && j>left)
                j--;
            if(i<j)
            {
                tmp=list[i];
                list[i]=list[j];
                list[j]=tmp;
            }
        }

        tmp=list[j];
        list[j]=list[left];
        list[left]=tmp;

        QuickSort(left, j-1);
        QuickSort(j+1, right);
    }
}
