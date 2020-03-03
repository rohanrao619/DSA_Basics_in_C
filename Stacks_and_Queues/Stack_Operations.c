#include<stdio.h>
#include<stdlib.h>
#define SS 50		// SS is Stack Size

int top=-1,stack[SS];
void push()        // Function to insert element in Stack
{
    int item;
    if(top==SS-1)   // Check Overflow condition
    {
        printf("\nStack is full!\n");
    }
    else
    {
        printf("\nEnter element to push:");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;   // Element inserted in Stack
    }
}

void pop()     // Function to delete elements from Stack
{
    if(top==-1)		// Check if stack is empty
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nDeleted element is %d",stack[top]);
        top=top-1;		// Element deleted from Stack
    }
}

void display()       // Function to show elements of Stack
{
    int i;

    if(top==-1)      //  Check if stack is empty
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nStack is as follows :\n");
        for(i=top; i>=0; --i)
            printf("%d\n",stack[i]);         // Display Stack
    }
}

void main()      
{						// Start main()
    int ch;
    while(1)
    {
        printf("\nStack Operations");
        printf("\n\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\n\nEnter your choice(1-4):");
        scanf("%d",&ch);

        switch(ch)			// Select Stack Operation
        {
        case 1:
            push();   // Call push function
            break;
        case 2:
            pop();   // Call pop function
            break;
        case 3:
            display();   // Call display function
            break;
        case 4:
            exit(0);

        default:
            printf("\nWrong Choice!");
	    break;
        }
    }
}		// End main()

