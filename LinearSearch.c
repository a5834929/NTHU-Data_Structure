#include<stdio.h>
#include<time.h>
int list[1000000]={0};

int main(int argc, char* argv[])
{
    int len, num, x, y, i, count;
    //double start, end;
    FILE* fpr, *fpw;

    //start=clock();

    fpr=freopen(argv[1], "r", stdin);
    fpw=freopen(argv[2], "w+", stdout);

    scanf("%d\n", &len);

    for(i=0;i<len;i++) scanf("%d", &list[i]);

    scanf("%d\n", &num);

    while(num--)
    {
        count=0;
        scanf("%d %d", &x, &y);

        for(i=0;i<len;i++)
        {
            if(list[i]>=x && list[i]<=y) count++;
        }

        printf("%d\n", count);
    }

    //end=clock();

    //printf("execution time = %.15lf\n", (end-start)/CLOCKS_PER_SEC);

    fclose(fpr);
    fclose(fpw);

    return 0;
}
