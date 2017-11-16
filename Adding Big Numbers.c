#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[100000], str2[100000];
int num1[100000]={0}, num2[100000]={0}, num3[100000]={0};

int main(void)
{

    int i, carry, lenmax, flag, point;
    char oper;

    scanf("%s", str1);
    scanf(" %c ", &oper);
    scanf("%s", str2);

    for(i=0;i<strlen(str1);i++) num1[i]=str1[strlen(str1)-i-1]-'0';
    for(i=0;i<strlen(str2);i++) num2[i]=str2[strlen(str2)-i-1]-'0';

    lenmax=(strlen(str1)>strlen(str2))?strlen(str1):strlen(str2);
    carry=0;
    flag=0;
    point=0;

    switch(oper)
    {
        case'+':    for(i=0;i<=lenmax;i++)
                    {
                        num3[i]=num1[i]+num2[i];
                        num3[i]+=carry;
                        carry=num3[i]/10;
                        num3[i]%=10;
                    }
                    for(i=lenmax;i>=0;i--)
                    {
                        if(num3[i]!=0)
                        {
                            point=i;
                            break;
                        }
                    }
                    for(i=point;i>=0;i--) printf("%d", num3[i]);
                    break;

        case'-':    if(strlen(str1)>strlen(str2))
                    {
                        for(i=0;i<lenmax;i++)
                        {
                           if(num1[i]<num2[i])
                           {
                               num3[i]=num1[i]+10-num2[i];
                               num1[i+1]-=1;
                           }
                           else num3[i]=num1[i]-num2[i];
                        }
                        for(i=lenmax-1;i>=0;i--)
                        {
                            if(num3[i]!=0)
                            {
                                point=i;
                                break;
                            }
                        }
                        for(i=point;i>=0;i--) printf("%d", num3[i]);
                    }

                    else if(strlen(str1)<strlen(str2))
                    {
                        for(i=0;i<lenmax;i++)
                        {
                           if(num1[i]>num2[i])
                           {
                               num3[i]=num2[i]+10-num1[i];
                               num2[i+1]-=1;
                           }
                           else num3[i]=num2[i]-num1[i];
                        }
                        printf("-");
                        for(i=lenmax-1;i>=0;i--)
                        {
                            if(num3[i]!=0)
                            {
                                point=i;
                                break;
                            }
                        }
                        for(i=point;i>=0;i--) printf("%d", num3[i]);
                    }

                    else
                    {
                        for(i=lenmax-1;i>=0;i--)
                        {
                            if(num1[i]<num2[i])
                            {
                                flag=1;
                                break;
                            }
                            else if(num1[i]>num2[i]) break;
                            else if(i==0)
                            {
                                flag=2;
                                printf("0");
                            }
                        }
                        if(flag==1)
                        {
                            for(i=0;i<lenmax;i++)
                            {
                                if(num2[i]<num1[i])
                                {
                                    num3[i]=num2[i]+10-num1[i];
                                    num2[i+1]-=1;
                                }
                                else num3[i]=num2[i]-num1[i];
                            }
                            printf("-");
                            for(i=lenmax-1;i>=0;i--)
                            {
                                if(num3[i]!=0)
                                {
                                    point=i;
                                    break;
                                }
                            }
                            for(i=point;i>=0;i--) printf("%d", num3[i]);
                        }
                        else if(flag==0)
                        {
                            for(i=0;i<lenmax;i++)
                            {
                                if(num1[i]<num2[i])
                                {
                                    num3[i]=num1[i]+10-num2[i];
                                    num1[i+1]-=1;
                                }
                                else num3[i]=num1[i]-num2[i];
                            }
                            for(i=lenmax-1;i>=0;i--)
                            {
                                if(num3[i]!=0)
                                {
                                    point=i;
                                    break;
                                }
                            }
                            for(i=point;i>=0;i--) printf("%d", num3[i]);
                        }
                        flag=0;
                        break;
                     }
    }
    printf("\n");

    return 0;
}
