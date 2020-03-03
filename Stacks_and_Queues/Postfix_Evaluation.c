#include<stdio.h>
#include<math.h>
#define MSS 20    // MSS is Maximum Stack Size
int stk[MSS];
int top=-1;
void push(int n)   // Function to insert element in Stack
{
    stk[++top]=n;   // Element inserted
}
int pop()       // Function to delete element from Stack
{
    return stk[top--];  // Element deleted
}
void main()
{        // Start main()
    char post_exp[MSS];
    char *ch;
    int num1,num2,num3,num;
    printf("Enter the Postfix_Expression (Max %d characters) : ",MSS-1);
    scanf("%s",post_exp);
    ch=post_exp;
    while(*ch!='\0')
    {
        if(isdigit(*ch))
        {
            num=*ch-48;
            push(num);   // Push digit into Stack
        }
        else
        {
            num1=pop();
            num2=pop();
            switch(*ch)    // Select Operator
            {
            case '+':
                num3=num1+num2;
                break;

            case '-':
                num3=num1-num2;
                break;

            case '*':
                num3=num1*num2;
                break;

            case '/':
                num3=num1/num2;
                break;

            case '^':
                num3=pow(num2,num1);
                break;
            }
            push(num3);  // Push result back into Stack
        }
        ch++;
    }
    printf("\nThe result of the Postfix_Expression is %d\n",num3);     // Display Result
}    // End main()
