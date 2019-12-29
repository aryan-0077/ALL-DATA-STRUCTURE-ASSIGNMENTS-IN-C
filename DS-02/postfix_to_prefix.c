#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define MAX 20
char str[MAX],stack[MAX];
int top=-1;

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
void push(char c)
{
   stack[++top]=c;
}
char pop()
{
   return stack[top--];
}
void main()
{
   int n,i,j=0; char c[20];
   char a,b,op;
   printf("Enter the postfix expression\n");
   scanf("%s",str);
   n=strlen(str);
   for(i=0;i<MAX;i++)
   stack[i]='\0';
   printf("Prefix expression is:\t");
   for(i=n-1;i>=0;i--)
   {
      if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='^')
      {
         push(str[i]);
      }
      else
      { c[j++]=str[i];
        while((top!=-1)&&(stack[top]=='@'))
        {
            a=pop(); c[j++]=pop();
        }
        push('@');
      }
   }
   c[j]='\0';
   printf("%s\n",strrev(c));
}
