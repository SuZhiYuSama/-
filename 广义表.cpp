#include<stdio.h>
#include<string.h>
char list[500];
int tag1,tag2,designator,pri;
void PrintGlist()
{
    for(int i=tag1;i<=tag2;i++)  printf("%c",list[i]);  
    printf("\n");
}
void GetHead()
{
    printf("destroy tail\nfree list node\ngeneric list: ");
    pri=-1;
    for(int i=tag1; list[i]!='\0'; i++)
    {
        switch(list[i])
        {
            case '(':
            pri++;
            if(!pri) tag1=i+1;
            break;
            case ')':
            pri--;
            if(!pri)
            {
                tag2=i;
                goto j;
             }
            break;
            case ',':
            if(!pri)
            {
                tag2=i-1;
                goto j;
             }
            break;
            default: break;
        }
    }
    j:PrintGlist();
}
void GetTail()
{
    printf("free head node\nfree list node\ngeneric list: ");
    pri=-1;
    int emp=0;
    for(int i=tag1;list[i]!='\0';i++)
    {
        if(i==tag2)
        {
            emp=1;
            break;
        }
        switch(list[i])
        {
            case '(':pri++; break;
            case ')':pri--; break;
            case ',':
            if(!pri) 
            { 
                list[i]='(';
                tag1=i;
                goto k;
             }
             default: break;
        }
    }
    k:if(emp)
    {
        printf("()\n");
        return;
    }
    PrintGlist();
}
int main(){
    scanf("%s",&list);
    printf("generic list: %s\n",list);
    tag1=0;
    tag2=strlen(list)-1;
    while(~scanf("%d",&designator))
    {
        switch(designator)
        {
            case 1: GetHead();   break;
            case 2: GetTail();   break;
        }
    }
    return 0;
}
