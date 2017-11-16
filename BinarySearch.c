#include<stdio.h>
#include<time.h>
int list[1000000]={0};

int main(int argc, char* argv[])
{
    int len, num, x, y, i;
    int left, right, left1, mid1, mid2;
    int flag1, flag2;
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
        scanf("%d %d", &x, &y);
        left=0;
        right=len-1;
        flag1=0;
        flag2=0;

        while(left<=right)
        {
            mid1=(left+right)/2;
            if(list[mid1]==x)
            {
                flag1=1;
                break;
            }
            if(list[mid1]>x) right=mid1-1;
            if(list[mid1]<x) left=mid1+1;
        }

        left1=0;
        right=len-1;

        while(left1<=right)
        {
            mid2=(left1+right)/2;
            if(list[mid2]==y)
            {
                flag2=1;
                break;
            }
            if(list[mid2]>y) right=mid2-1;
            if(list[mid2]<y) left1=mid2+1;
        }

        while(x==list[mid1])
        {
            if(list[mid1]==list[mid1-1]) mid1--;
            else break;
        }
        while(y==list[mid2])
        {
            if(list[mid2]==list[mid2+1]) mid2++;
            else break;
        }

        if(flag2 && flag1) printf("%d\n", mid2-mid1+1);
        else if(flag2 && !flag1) printf("%d\n", mid2-left+1);
        else if(!flag2 && flag1) printf("%d\n", left1-mid1);
        else printf("%d\n", left1-left);
    }
    //end=clock();

    //printf("execution time = %.15lf\n", (end-start)/CLOCKS_PER_SEC);

    fclose(fpr);
    fclose(fpw);

    return 0;
}
