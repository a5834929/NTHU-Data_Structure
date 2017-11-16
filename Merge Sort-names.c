#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct p
{
    char name[100];
}NAME;

NAME list[60000];

typedef struct P
{
    char name[100];
}NaMe;

NaMe c[60000];

void mergesort(int start, int end);
void merge(int start, int end, int mid);

int main(void)
{
    int i, j;
    char c;

    freopen("names.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);

    i=0;
    j=0;
    while(scanf("%c", &c)!=EOF)
    {
        if(isalpha(c))
        {
            list[i].name[j]=c;
            j++;
        }
        else
        {
            if(j)
            {
                list[i].name[j]='\0';
                i++;
            }
            j=0;
        }
    }

    mergesort(0, i-1);

    for(j=0;j<i;j++)
            printf("%s\n", list[j].name);

    return 0;
}

void mergesort(int start, int end)
{
    int mid;

    if(end>start)
    {
        mid=(start+end)/2;
        mergesort(start, mid);
        mergesort(mid+1, end);
        merge(start, mid, end);
    }

    return;
}

void merge(int start, int mid, int end)
{
    int i,j,k;

    i=k=start;
    j=mid+1;

    while(i<=mid && j<=end)
    {
        if(strcmp(list[i].name, list[j].name)<=0)
        {
            strcpy(c[k].name, list[i].name);
            i++;
            k++;
        }

        else if(strcmp(list[i].name, list[j].name)>0)
        {
            strcpy(c[k].name, list[j].name);
            j++;
            k++;
        }
    }

    while(i<=mid && j>end)
    {
        strcpy(c[k].name, list[i].name);
        i++;
        k++;
    }

    while(j<=end && i>mid)
    {
        strcpy(c[k].name, list[j].name);
        j++;
        k++;
    }

    for(i=start;i<k;i++)
        strcpy(list[i].name, c[i].name);

    return;
}
