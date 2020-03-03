#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MSS 25    // MSS is Maximum Stack Size
int sp(char symbol)  // Function to return Stack precedence
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
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
    case '$':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default :
        return 7;
    }
}
void infix_to_postfix(char infix[],char postfix[])	// Function to convert infix expression to postfix expression
{
    int top, j, i;
    char stk[MSS], symbol;
    top=-1;
    stk[++top]='#';
    j=0;
    for(i=0; i<strlen(infix); i++)
    {
        symbol=infix[i];
        while(sp(stk[top])>ip(symbol))
            postfix[j++]=stk[top--];
        if(sp(stk[top]!=ip(symbol)))
            stk[++top]=symbol;
        else
            top--;
    }
    while(stk[top]!='#')
        postfix[j++]=stk[top--];
    postfix[j]='\0';
}
void main()
{   int i;   		// Start main()
    char infix[MSS], postfix[MSS];
    printf("Enter a valid Infix Expression ( Max. %d characters ): ",MSS-1);
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);   // Call infix_to_postfix Function
    printf("The Postfix Expression is : ");
    for(i=0; postfix[i]!='\0'; i++)
        if(postfix[i]!='('&&postfix[i]!=')')
            printf("%c",postfix[i]);   // Display Postfix Expression
}         // End main()
