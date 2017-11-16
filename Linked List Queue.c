#include<stdio.h>
#include<stdlib.h>
typedef struct list_node * list_pointer;
typedef struct list_node{
    int data;
    list_pointer next;
};
typedef struct list_node list_node;

void push(list_pointer,int num);
void pop(list_pointer);

int main(void)
{
    list_pointer first,node;
    int num,x;
    char ch;

    first=(list_pointer)malloc(sizeof(list_node));

    scanf("%d",&first->data);
    first->next=NULL;

    while((ch=getchar())!='q')
    {
        scanf("%d",&x);
        if(x)
        {
            scanf("%d",&num);
            for(node=first;node!=NULL;node=node->next)
                    if(node->next==NULL)
                        break;
            push(node,num);
        }

        else
        {
            node=first;
            first=node;
            pop(node);
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

void push(list_pointer node,int num){

    list_pointer temp;

    temp=(list_pointer)malloc(sizeof(list_node));

    temp->data=num;
    node->next=temp;
    temp->next=NULL;

}
void pop(list_pointer node){

    node->data=node->next->data;
    node->next=node->next->next;
}
