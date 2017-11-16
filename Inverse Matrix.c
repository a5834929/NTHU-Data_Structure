#include <stdio.h>

double det(double (*a)[10], int N);
void cof(double (*a)[10], double (*b)[10], int col, int N);

int main(void)
{
    int i, j, N;
    double mat[10][10]={{0}};

    scanf("%d\n", &N);

    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf ("%lf",&mat[i][j]);

    printf("%.0lf\n", det(mat, N));

    return 0;
}

void cof(double (*a)[10], double (*b)[10], int col, int N)
{
    int i, j, k=0, l=0;

    for(i=0;i<N;i++)
    {
        if(i==0) continue;  //第一列不存進新矩陣
        for(j=0;j<N;j++)
        {
            if(j==col) continue; //
            b[k][l]=a[i][j];
            l++;
        }
        k++;
        l=0;
    }
}

double det(double (*a)[10], int N)
{
    int i;
    double x=0, sum=0;
    double b[10][10]={{0}};

    if(N==1) return a[0][0];
    if(N==2) return a[0][0]*a[1][1]-a[1][0]*a[0][1];
    if(N==3) return a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
                  - a[1][0]*(a[0][1]*a[2][2]-a[0][2]*a[2][1])
                  + a[2][0]*(a[0][1]*a[1][2]-a[0][2]*a[1][1]);
    else
    {
        for(i=0;i<N;i++)
        {
            cof(a, b, i, N);  //降階,把新矩陣存進b
            if(i%2==0) x=1;   //i為偶數時要乘以1
            else x=-1;          //i為奇數時要乘以-1
            sum+=a[0][i]*det(b, N-1)*x; //算行列式值
        }
    }

    return sum;
}
