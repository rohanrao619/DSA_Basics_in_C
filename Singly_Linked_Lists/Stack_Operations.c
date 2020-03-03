#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int item;
struct node   // Define Node of Linked List
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode()  // Fuction to Create new Node
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));  // New Node created
    if(temp==NULL)  // Check if Memory is full
    {
        printf("No memory left!\n");
        exit(0);
    }
    return temp;  
}
NODE push(NODE first,int item)    // Function to insert element in Stack
{
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)  // Check if Stack is Empty
        return temp;
    else
    {
        cur=first;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;
        return first;
    }
}
NODE display(NODE first)     // Function to show elements of Stack
{
    NODE cur;
    cur=first;
    if(first==NULL)     //  Check if stack is empty
    {
        printf("Stack is empty!\n");
        return NULL;
    }
    else
    {
        printf("The Stack content is : ");
        while(cur->link!=NULL)
        {
            printf("%d  ",cur->info);   // Display Stack
            cur=cur->link;
        }
        printf("%d\n",cur->info);   // Display Stack
        return first;
    }
}
NODE pop(NODE first)   // Function to delete elements from Stack
{
    NODE cur;
    NODE prev;
    cur=first;
    prev=NULL;
    if(first==NULL)    // Check if stack is empty
    {
        printf("The stack is empty ! \n");
        return NULL;
    }
    else if(first->link==NULL)  
    {
        printf("The deleted item is : %d\n",first->info);
        free(first);   // Element deleted
        return NULL;
    }
    else
    {
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("The deleted item is : %d\n",cur->info);
        free(cur); // Element deleted
        prev->link=NULL;
        return first;
    }
}
void main()      
{   NODE first=NULL;         // Start main()
    int ch;
    while(1)
    {
        printf("Stack menu :\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)   // Select Operation
        {
        case 1:
            printf("Insert the item to push in stack: ");
            scanf("%d",&item);
            first=push(first,item);  // Call push function
            break;
        case 2:
            first=pop(first);     // Call pop function
            break;
        case 3:
            first=display(first);     // Call display function
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice ! \n");
            break;
        }
    }

}    // End main()
