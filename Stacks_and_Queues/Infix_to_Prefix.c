#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MSS 25    // MSS is Maximum Stack Size
int sp(char symbol)    // Function to return Stack precedence
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case')':
        return 0;
    case '#':
        return -1;
    default :
        return 8;
    }
}
int ip(char symbol)     // Function to return Input precedence
{
    switch(symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
    case '$':
        return 5;
    case '(':
        return 0;
    case ')':
        return 9;
    default :
        return 7;
    }
}
void infix_to_prefix(char infix[],char prefix[])  // Function to convert infix expression to prefix expression
{           
    int top, j, i;    
    char stk[MSS], symbol;
    top=-1;
    stk[++top]='#';
    j=0;
    strrev(infix);
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        while(sp(stk[top])>ip(symbol))
            prefix[j++]=stk[top--];
        if(sp(stk[top]!=ip(symbol)))
            stk[++top]=symbol;
        else
            top--;
    }
    while(stk[top]!='#')
        prefix[j++]=stk[top--];
    prefix[j]='\0';
    strrev(prefix);
}
void main()
{   int i;      // Start main()
    char infix[MSS], prefix[MSS];
    printf("Enter a valid Infix Expression ( Max. %d characters ): ",MSS-1);
    scanf("%s", infix);
    infix_to_prefix(infix, prefix);   // Call infix_to_prefix Function
    printf("The Prefix Expression is : ");
    for(i=0; prefix[i]!='\0'; i++)
        if(prefix[i]!='('&&prefix[i]!=')')
            printf("%c",prefix[i]);     // Display Postfix Expression
}       // End main()
