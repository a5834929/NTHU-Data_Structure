#include<stdio.h>
#include<time.h>
int GCD(int x, int y);

int main(void)
{
    time_t start, end;
    int x, y;
    float exetime;
    FILE* fp;
    fp=fopen("input.txt","r");
    start=clock();

    fscanf(fp, "%d %d", &x, &y);

    printf("(%d, %d) = %d\n", x, y, GCD(x,y));

    close(fp);
    end=clock();
    exetime=(float)(end-start)/CLOCKS_PER_SEC;
    printf("execution time = %f\n", exetime);

    return 0;
}

int GCD(int x, int y)
{
    int gcd;
    if(x%y!=0 && y%x!=0)
    {
        if(x>y) gcd=GCD(x%y, y);
        else gcd=GCD(x,y%x);

        return gcd;
    }
    else return (x>y)?y:x;
}
