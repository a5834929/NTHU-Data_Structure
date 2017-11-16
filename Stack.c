#include<stdio.h>
#include<string.h>
void push(char stack[], char c, int top);
void pop(char stack[], int top);

int main(void)
{
    char com[10], stack[5], c, h;
    int top, j;
    top=0;
    while(scanf("%s", com)!=EOF)
    {
        if(strcmp(com,"PUSH")==0)
        {
            scanf("%c%c", &h, &c);
            push(stack, c, top);
            top++;
        }
        else if(strcmp(com,"POP")==0)
        {
            pop(stack, top);
            if(top!=0) top--;
        }
        else if(strcmp(com,"PRINT")==0)
        {
            for(j=0;j<top;j++) printf("%c", stack[j]);
        }
        else if(strcmp(com,"QUIT")==0) break;
    }

    return 0;
}

void push(char stack[], char c, int top)
{
   if(top==4) printf("The stack is full.\n");

   else stack[top]=c;
}

void pop(char stack[], int top)
{
   if(top==0) printf("The stack is empty.\n");
}
