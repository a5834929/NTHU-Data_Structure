#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int check1[100]={0};
int check2[100][100]={0};
void nodeDFS(int i);
void edgeDFS(int i);
typedef struct node* node_pointer;
typedef struct node
{
    int data;
    node_pointer next;
}node;

int AdjMatrix[15][15]={0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
                       1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
                       0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
                       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
                       0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                       0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};

node_pointer AdjList[15]={0};

void ConstructList()
{
    node_pointer temp, target;
    for(int row=0;row<15;row++)
    {
        for(int col=0;col<15;col++)
        {
            if(AdjMatrix[row][col])
            {
                temp=(node_pointer)malloc(sizeof(node));
                temp->data=col;
                temp->next=NULL;

                if(AdjList[row]==NULL)
                    AdjList[row]=temp;

                else
                {
                    target=AdjList[row];

                    while(target->next!=NULL)
                    {
                        target=target->next;
                    }

                    target->next=temp;
                }
            }
        }
    }
    return;
}

int main(int argc, char*argv[])
{
    int i;
    ConstructList();

    for(i=0;i<15;i++)
        nodeDFS(i);

    printf("\n");

    for(i=0;i<15;i++)
        edgeDFS(i);

    return 0;
}

void nodeDFS(int i)
{
    node_pointer tmp;
    if(AdjList[i]==NULL)
    {
        printf("%d ", i);
        check1[i]=1;
        return;
    }

    else
    {
        tmp=AdjList[i];
        while(tmp)
        {
            if(!check1[i])
            {
                printf("%d ", i);
                check1[i]=1;
                nodeDFS(tmp->data);
            }
            tmp=tmp->next;
        }
        return;
    }
}

void edgeDFS(int i)
{
    node_pointer tmp;
    int k=0;
    if(AdjList[i]==NULL)
    {
        printf("(%d, %d) ", i, AdjList[i]->data);
        check2[AdjList[i]->data][i]=1;
        k=i;
        return;
    }

    else
    {
        tmp=AdjList[i];
        while(tmp)
        {
            if(!check2[i][tmp->data])
            {
                if(k!=i) printf("\n");
                printf("(%d, %d) ", i, tmp->data);
                check2[tmp->data][i]=1;
                k=i;
            }

            tmp=tmp->next;
        }
        return;
    }
}
