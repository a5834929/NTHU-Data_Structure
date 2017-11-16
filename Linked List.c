#include<stdio.h>
#include<stdlib.h>
typedef struct list_node *list_pointer;
typedef struct list_node{
    int data;
    list_pointer next;
};

typedef struct list_node list_node;

void pushf(list_pointer,int num);
void popf(list_pointer);
void pushr(list_pointer,int num);
void popr(list_pointer);
list_pointer first;

int main(void)
{
    list_pointer node, temp;
    int num, x1, x2;
    char ch;

    first=(list_pointer)malloc(sizeof(list_node));

    scanf("%d",&first->data);
    first->next=NULL;

    while((ch=getchar())!='q')
    {
        scanf("%d",&x1);
        if(x1)
        {
            scanf("%d", &x2);

            if(x2)
            {
                scanf("%d",&num);
                node=first;

                pushf(node,num);
            }

            else
            {
                scanf("%d",&num);

                for(node=first;node!=NULL;node=node->next)
                    if(node->next==NULL)
                        break;

                pushr(node,num);
            }
        }

        else
        {
            scanf("%d", &x2);
            if(x2)
            {
                node=first;
                first=node;
                popf(node);
            }

            else
            {
                for(node=first;node!=NULL;node=node->next)
                    if(node->next->next==NULL)
                        break;
                popr(node);
            }
        }

        node=first;

        while(node!=NULL)
        {
            printf("%d ",node->data);
            node=node->next;
        }
        printf("\n");
    }

    return 0;
}

void pushr(list_pointer node,int num)
{
    list_pointer temp;

    temp=(list_pointer)malloc(sizeof(list_node));

    temp->data=num;
    node->next=temp;
    temp->next=NULL;
}
void pushf(list_pointer node,int num)
{
    list_pointer temp;

    temp=(list_pointer)malloc(sizeof(list_node));

    temp->data=num;
    temp->next=node;
    first=temp;
}
void popr(list_pointer node)
{
    node->next=NULL;
}
void popf(list_pointer node)
{
    node->data=node->next->data;
    node->next=node->next->next;
}
