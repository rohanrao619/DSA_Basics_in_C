#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int item;
struct node       // Define Node of Linked List
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
int item;
NODE first;
NODE getnode()    // Fuction to Create new Node
{
    NODE n;
    n=(NODE)malloc(sizeof(struct node));  // New Node created
    if(n==NULL)    // Check if Memory is full
    {
        printf("No memory left!\n");
        exit(0);
    }
    return n;
}
NODE ins_rear(NODE first,int item)  // Function to insert element in Queue
{
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)  // Check if Queue is Empty
        return temp;
    else
    {
        cur=first;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;    //Element inserted
        return first;
    }
}
NODE display(NODE first)   // Function to show elements of Queue
{
    NODE cur;
    cur=first;
    if(first==NULL)   //  Check if Queue is empty
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    else
    {
        printf("\n Que elements are :  ");
        while(cur->link!=NULL)
        {
            printf("%d  ",cur->info);   // Display Queue
            cur=cur->link;
        }
        printf("%d\n",cur->info);   // Display Queue
        return first;
    }
}
NODE del_front(NODE first)  // Function to delete elements from Queue
{
    NODE cur;
    cur=first;
    if(first==NULL)   // Check if Queue is empty
    {
        printf("Queue is empty!\n");
        return NULL;
    }
    else
    {
        cur=cur->link;
        printf("The deleted item is : %d\n",first->info);
        free(first);  // Element deleted
        return cur;
    }
}
void main()
{            // Start main()
    int ch;
    while(1)
    {
        printf("Queue Menu :\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)       // Select Operation
        {
        case 1:
            printf("Insert the item to insert : ");
            scanf("%d",&item);
            first=ins_rear(first,item);  // Call ins_rear function
            break;
        case 2:
            first=del_front(first);  // Call del_front function
            break;
        case 3:
            first=display(first);   // Call display function
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Choice !\n ");
        }
    }

}    // End main()
