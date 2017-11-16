#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>
int in[10010];
void inDFS(int now, int len);
void preDFS(int now, int len);
void postDFS(int now, int len);
void inDFSm(int now, int len);
void preDFSm(int now, int len);
void postDFSm(int now, int len);

int main(void)
{
    int i, j;

    memset(in, -1, sizeof(in));
    i=1;

    while(scanf("%d", &in[i++])!=EOF);

    inDFS(1, i-1);
    printf("\n");
    preDFS(1, i-1);
    printf("\n");
    postDFS(1, i-1);

    inDFSm(1, i-1);
    printf("\n");
    preDFSm(1, i-1);
    printf("\n");
    postDFSm(1, i-1);

    return 0;
}

void inDFS(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        if(now*2<=len)
            inDFS(now*2, len);
        printf("%d ", in[now]);
        if(now*2+1<=len)
            inDFS(now*2+1, len);
        return;
    }
}

void preDFS(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        printf("%d ", in[now]);
        if(now*2<=len)
            preDFS(now*2, len);
        if(now*2+1<=len)
            preDFS(now*2+1, len);
        return;
    }
}

void postDFS(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        if(now*2<=len)
            postDFS(now*2, len);
        if(now*2+1<=len)
            postDFS(now*2+1, len);
        printf("%d ", in[now]);
        return;
    }
}

void inDFSm(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        if(now*2+1<=len)
            inDFSm(now*2+1, len);
        printf("%d ", in[now]);
        if(now*2<=len)
            inDFSm(now*2, len);
        return;
    }
}

void preDFSm(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        printf("%d ", in[now]);
        if(now*2+1<=len)
            preDFSm(now*2+1, len);
        if(now*2<=len)
            preDFSm(now*2, len);
        return;
    }
}

void postDFSm(int now, int len)
{
    if(in[now]==-1)
        return;

    else
    {
        if(now*2+1<=len)
            postDFSm(now*2+1, len);
        if(now*2<=len)
            postDFSm(now*2, len);
        printf("%d ", in[now]);
        return;
    }
}

