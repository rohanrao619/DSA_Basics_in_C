#include<stdio.h>
#include<stdlib.h>
#define MSS 20		// MSS is Maximum Stack Size
#define NOS 5		// NOS is number of Stacks
void push(int item,int stkno,int top[],int bndry[],int stk[])   // Function to insert element in a Sub-Stack
{
    if(top[stkno]==bndry[stkno+1])    // Check Overflow condition
    {
        printf("\nStack %d is full\n",stkno);
        return;
    }
    top[stkno]++;
    stk[top[stkno]]=item;     // Element inserted in a Sub-Stack
}
int pop(int stkno,int top[],int bndry[],int stk[])     // Function to delete element from a Sub-Stack
{   int ele;
    if(top[stkno]==bndry[stkno])   // Check Underflow Condition
        return -1;
    else
    {
        ele=stk[top[stkno]];
        top[stkno]--;       // Element deleted from a Sub-Stack
        return ele;
    }
}
void display(int stkno,int top[],int bndry[],int stk[])      // Function to display elements of a Sub-stack
{
    int i;
    if(top[stkno]==bndry[stkno])    // Check if Sub-Stack is empty
    {
        printf("Stack %d is empty!\n",stkno);
    }
    else
    {
        for(i=top[stkno]; i>=bndry[stkno]+1; i--)
            printf("%d\n",stk[i]);    // Display Sub-Stack elements
    }
}
void main()
{             // Start main()
    int stk[MSS],bndry[NOS],top[NOS];
    int ch,j,n,ch1,val,item;
    printf("Enter the number of stacks (Max. %d) (Size of main Stack is %d): ",NOS,MSS);
    scanf("%d",&n);
    for(j=0; j<n; j++)    // Loop to determine top and bndry values for Sub-Stacks
    {
        top[j]=MSS/n*j-1;
        bndry[j]=MSS/n*j-1;
    }
    while(1)
    {
        printf("The Stacks available are : \n");
        for(j=0; j<n; j++)
            printf("Stack %d\n",j);
        printf("Enter the Stack for performing opration (Enter 99 to exit) : ");
        scanf("%d",&ch1);
        if(ch1==99)
            exit(0);
        if(ch1<0||ch1>n-1)
        {   printf("No such stack available\n");
            continue;
        }
        printf("Stack Menu:\n 1:PUSH\n 2:POP\n 3:DISPLAY\n 4:EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)    // Select Operation
        {
        case 1:
            printf("Enter item to be pushed : ");
            scanf("%d",&item);
            push(item,ch1,top,bndry,stk);  // Call push function
            break;
        case 2:
            val = pop(ch1,top,bndry,stk);   // Call pop function
            if(val==-1)
            {
                printf("Stack %d is empty \n",ch1);
            }
            else
            {
                printf("The deleted item is:%d\n",val);
            }
            break;
        case 3:
            display(ch1,top,bndry,stk);     // Call display function
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n Wrong choice!\n",val);
	    break;
        }
    }
}       // End of main()


