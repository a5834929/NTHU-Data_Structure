#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5

int main(void)
{
    char com[10], c, h;
    int front, rear;
    front=0;
    rear=0;

    char* queue=(char*)malloc(size*sizeof(char));

    while(scanf("%s", com)!=EOF)
    {
        if(strcmp(com, "ADD")==0)
        {
            scanf("%c%c", &h, &c);

            if(rear<size)
            {
                queue[rear]=c;
                rear++;
            }
            else
            {
                queue=(char*)realloc(queue, 2*size*sizeof(char));
                queue[rear]=c;
                rear++;
            }
        }

        if(strcmp(com, "DELETE")==0)
        {
            if(front>=rear) printf("The queue is empty.\n");
            front++;
        }

        if(strcmp(com, "PRINT")==0) printf("%c\n", queue[front-1]);

        if(strcmp(com, "QUIT")==0) break;
    }

    return 0;
}
