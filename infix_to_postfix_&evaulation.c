#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
char infix[50],postfix[50],Stack[35];
int top=-1,p_tp=-1,iStack[30],itop=-1;
int ipop()
{  
    int item=iStack[itop];
    itop--;
    return item;
}
void ipush(int n)
{
    iStack[++itop]=n;
}
char pop()
{  
    char item=Stack[top];
    top--;
    return item;
}
void push(char n,char *arr,int *top)
{
    ++(*top);
    *(arr+*top)=n;//arr[*top]=n
}
int do_operation(int a,int b,char c)
{
    switch (c)
    {
    case '+':return b+a;
    case '-':return b-a;
    case '*':return b*a;
    case '/':return b/a;
    case '^':return pow(b,a);
    }
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
    case '(':return 0;// default:printf("\n Invalid Operator!! %c\n",op);//         break;
    }
}
void operator_assign(char op)
{
   int n_p,o_p;
   n_p=get_precedence(op);
   o_p=get_precedence(Stack[top]);
  
  while(n_p<=o_p && top>-1) 
  {
    if(n_p == o_p && n_p==3)
          break;
    push(pop(),postfix,&p_tp);
    o_p=get_precedence(Stack[top]);
  }
  push(op,Stack,&top);
    //printf(" %d %d %c\n",n_p,o_p,st[t]);
}

//postfix
void main()
{
    int i,j,l;
    printf("\n Enter the infix expression:");
    scanf("%s",infix);
    l=strlen(infix);
    if(isalnum(infix[l-1]) || infix[l-1]==')')
     {
      for(i=0;i<l;i++)
      {
        if(isalnum(infix[i]))//printf("%c",infix[i]);
           push(infix[i],postfix,&p_tp);
        else
        {
            if(infix[i]=='(')
               push(infix[i],Stack,&top);
            else
               { 
                 if(infix[i]==')')
                  {
                   for(j=top;j>=0;j--)
                     if(Stack[j]=='(')
                     {   pop();
                        break;
                     }else
                        push(pop(),postfix,&p_tp);
                 }
                 else
                    operator_assign(infix[i]);
           }
        }
      }
      for(i=top;i>=0;i--)
        postfix[++p_tp]=Stack[i];

      printf("\n Postfix Expression:");

      printf("%s",postfix);
    
    int op1,op2;
    for(i=0;i<=p_tp;i++)
        if(isalpha(postfix[i]))
              {
                printf("\n Enter the value of %c:",postfix[i]);
                int temp;
                scanf("%d",&temp);
                ipush(temp);
              }
        else if(isdigit(postfix[i]))
                ipush((postfix[i])-48);
             else
             {
                op1=ipop();
                op2=ipop();
                ipush(do_operation(op1,op2,postfix[i]));
             }
        if(itop==0)
        printf("\n Value after Evaluation: %d",iStack[itop]);
        
    }
    else
        printf("\n Invalid Expression");
} 