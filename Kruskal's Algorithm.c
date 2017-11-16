#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*p, const void*q);
void Union(int a, int b);
int find(int x);

typedef struct mat
{
    int from, to;
    int wei;
}MAT;

MAT graph[100000];
int set[100000];
int check[10000][10000];
int n;

int main(int argc, char *argv[])
{
    freopen(argv[1],"r",stdin);
    int i, j, k, a;
    int sum, num;

    while(scanf("%d", &n)!=EOF)
    {
        memset(graph, 0, sizeof(MAT));
        memset(check, 0, sizeof(int));
        k=0;
        sum=0;
        num=0;
        for(i=0;i<n;i++)
        {
            set[i+1]=i+1;
            for(j=0;j<n;j++)
            {
                scanf("%d", &a);

                if(i!=j)
                {
                    if(!check[i+1][j+1])
                    {
                        graph[k].wei=a;
                        graph[k].from=i+1;
                        graph[k].to=j+1;
                        check[j+1][i+1]=1;
                        k++;
                    }
                }
            }
        }

        qsort(graph, k, sizeof(MAT), cmp);

        for(i=0;i<k && num<n-1;i++)
        {
            if(set[graph[i].from]!=set[graph[i].to])
            {
                Union(graph[i].from, graph[i].to);
                num++;
                sum+=graph[i].wei;
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    MAT a=*(MAT*)p, b=*(MAT*)q;
    if(a.wei!=b.wei) return (a.wei<b.wei)?-1:1;
    else if(a.from!=b.from) return (a.from<b.from)?-1:1;
    return 0;
}

int find(int x)
{
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

void Union(int a, int b)
{
    int x, y;

    x=find(set[a]);
    y=find(b);

    if(x!=y)
        set[y]=x;

    return;
}
