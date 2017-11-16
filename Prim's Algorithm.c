#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[1100][1100];
int vert[1100];
int neartotree[1100];

int main(int argc, char* argv[]){
    int n, i, j, k, len, wei, sum, next;
    freopen(argv[1], "r", stdin);

    while(scanf("%d", &n)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d", &matrix[i][j]);

        vert[1]=1;
        neartotree[0]=1;
        i=1;
        sum=0;
        len=1;
        while(len<n){
            wei=9999;
            for(k=0;k<len;k++){
                i=neartotree[k];
                for(j=1;j<=n;j++){
                    if(matrix[i][j]!=9999){
                        if(vert[i] && !vert[j]){
                            if(matrix[i][j]<wei){
                                wei=matrix[i][j];
                                next=j;
                            }
                        }
                    }
                }
            }
            vert[next]=1;
            sum+=wei;
            neartotree[len]=next;
            len++;
        }
        printf("%d\n", sum);
    }
    return 0;
}
