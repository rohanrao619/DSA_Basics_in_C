#include<stdio.h>
#define MSS 50		// MSS is maximum Stack size
int stk[MSS];
int top=-1;
void push(int n)    // Fuction to push element in Stack
{
    stk[top+1]=n;     // Element inserted
    top++;
    return;
}
char pop()    // Fuction to pop element from Stack
{
    return stk[top--];
}
int main()   // Start main()
{   int i=0,j;
    int a,b,num,num1,temp[MSS];
    printf("Enter the Number : ");
    scanf("%d",&num);
    num1=num;
    while(num1!=0)   // Loop to insert elements of string into stack
    {
        a=num1%10;
        push(a);
        temp[i]=a;
        num1/=10;
        i++;
    }
    for(j=0; j<i/2; j++)    // Loop to check if number is palindrome
    {
        b=pop();
        if(b!=temp[j])
        {
            printf("%d is not a Palindrome\n",num);
            return 0;
        }
    }
    printf("%d is a Palindrome\n",num);
}      // End main()


