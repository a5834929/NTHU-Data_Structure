#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int list[1100];

int main(void)
{
    int i, j, n, tmp;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d", &list[i]);
            for(j=i;j>0;j--)
            {
                if(list[j]>list[j/2])
                {
                    tmp=list[j];
                    list[j]=list[j/2];
                    list[j/2]=tmp;
                }
            }
        }

        for(i=n-1;i>=0;i--)
        {
            printf("%d ", list[0]);

            list[0]=list[i];

            for(j=i-1;j>0;j--)
            {
                if(list[j]>list[j/2])
                {
                    tmp=list[j];
                    list[j]=list[j/2];
                    list[j/2]=tmp;
                }
            }
        }
    }
    return 0;
}
