#include<stdio.h>
#include<ctype.h>
#include<string.h>
char infix[50],Stack[35],prefix[50];
int top=-1,p_tp=-1;

char s_pop()
{  
    char item=Stack[top];
    top--;
    return item;
}
void push(char n,char *arr,int *top)
{
    ++(*top);
    *(arr+*top)=n;
}
int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':return 1;
    case '*':
    case '/':return 2;
    case '^':return 3;
    case ')':return 0;
    }
}
void operator_assign(char op)
{
   int n_p,o_p;
   n_p=get_precedence(op);
   o_p=get_precedence(Stack[top]);
      while(n_p<=o_p && top>-1)
      {
         if(n_p==o_p && n_p!=3)
           break;
        push(s_pop(),prefix,&p_tp);
        
        
         o_p=get_precedence(Stack[top]);
      }
      push(op,Stack,&top);
   
}

//prefix
void main()
{
    int i,j,l;
    
    printf("\n Enter the infix expression:");
    scanf("%s",infix);
    l=strlen(infix);
    if(isalnum(infix[l-1])||infix[l-1]==')')
     {
      for(i=l-1;i>=0;i--)
     {
        if(isalnum(infix[i]))
           push(infix[i],prefix,&p_tp);
        else
        {
            if(top==-1 || infix[i]==')')
               push(infix[i],Stack,&top);
            else
               {
                 if(infix[i]=='(')
                  {
                   for(j=top;j>=0;j--)
                     if(Stack[j]==')')
                     {   s_pop();
                        break;
                     }
                     else 
                        push(s_pop(),prefix,&p_tp);
                 }
                 else
                    operator_assign(infix[i]);
           }
        }
    }
    for(i=top;i>=0;i--)
        prefix[++p_tp]=Stack[i];
    printf("\n Prefix Expression:");
     for(i=p_tp;i>=0;i--)
       printf("%c",prefix[i]);
     }
     else
        printf("\n Invalid Expression");
     
}