#include<stdio.h>
#include<time.h>
int fibo(int n);

int main(void)
{
    time_t start, end;
    int n, i;
    float exetime;
    FILE* fp;
    //fp=fopen("input.txt","r");
    start=clock();

    scanf("%d", &n);

    for(i=1;i<=n;i++) printf("fibo(%d) = %d\n", i, fibo(i));

    close(fp);
    end=clock();
    exetime=(float)(end-start)/CLOCKS_PER_SEC;
    printf("execution time = %f\n", exetime);

    return 0;
}

int fibo(int n)
{
    if(n==1) return 0;
    if(n==2) return 1;
    else return fibo(n-1)+fibo(n-2);
}
