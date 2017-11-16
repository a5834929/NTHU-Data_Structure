#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num[2]={0}, i, k;
    int regis[3]={0}, min;

    while(scanf("%d %d %d", &i, &num[0], &num[1])!=EOF)
    {
        int j;

        for(j=0;j<3;j++)
        {
            if(regis[j]<=num[0])
            {
                printf("%d %d %d %d\n", i, j+1, num[0], num[0]+num[1]);
                regis[j]=num[0]+num[1];
                break;
            }
        }

        if(j>=3)
        {
            min=0;
            for(k=0;k<3;k++)
            {
                if(regis[k]<regis[min]) min=k;
            }
            printf("%d %d %d %d\n", i, min+1, regis[min], regis[min]+num[1]);
            regis[min]=regis[min]+num[1];
        }
    }

    return 0;
}

