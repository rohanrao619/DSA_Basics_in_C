#include<stdio.h>
#define MSS 50   // MSS is maximum Stack size
char stk[MSS];
int top=-1;
void push(char ch)   // Fuction to push element in Stack
{
    stk[top+1]=ch;   // Element inserted
    top++; 
    return;
}
char pop()     // Fuction to pop element from Stack
{
    return stk[top--];
}
int main()    // Start main()
{   int i,j;
    char a,b,str[MSS];
    printf("Enter the String (Max %d characters): ",MSS-1);
    scanf("%s",str);
    for(i=0; str[i]!='\0'; i++)  // Loop to insert elements of string into stack
    {
        a=str[i];
        push(a);
    }
    for(j=0; j<i/2; j++)   // Loop to check if string is palindrome
    {
        b=pop();
        if(b!=str[j])
        {
            printf("%s is not a Palindrome\n",stk);
            return 0;
        }
    }
    printf("%s is a Palindrome\n",stk);
}    // End main()


