#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node   // Define Node of Linked List
{
    int info;
    struct node *link;
};
typedef struct node *NODE;
NODE first;
int item;
NODE getnode()    // Fuction to Create new Node
{
    NODE n;
    n=(NODE)malloc(sizeof(struct node));  // New Node created
    if(n==NULL)   // Check if Memory is full
    {
        printf("No memory left!\n");
        exit(0);
    }
    return n;
}
NODE ins_front(NODE first,int item)   // Function to insert element from front end
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=first;  // Element inserted
    return temp;
}
NODE ins_rear(NODE first,int item)    // Function to insert element from rear end
{
    NODE temp;
    NODE cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(first==NULL)  // Check if List is Empty
        return temp;
    else
    {
        cur=first;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;   // Element inserted
        return first;
    }
}
NODE display(NODE first)      // Function to show elements of List
{
    NODE cur;
    cur=first;
    if(first==NULL)   // Check if List is Empty
    {
        printf("List is empty!\n");
        return NULL;
    }
    else
    {
        printf("Content is : ");
        while(cur->link!=NULL) 
        {
            printf("%d  ",cur->info);  // Display elements
            cur=cur->link;
        }
        printf("%d\n",cur->info);  // Display element
        return first;
    }
}
NODE del_front(NODE first)    // Function to delete elements from front end 
{ 
    NODE cur;
    cur=first;
    if(first==NULL)    // Check if List is Empty
    {
        printf("List is empty!\n");
        return NULL;
    }
    else
    {
        printf("Deleted element is %d\n",first->info);
        cur=cur->link;
        free(first);   // Element deleted
        return cur;
    }
}
NODE del_rear(NODE first)    // Function to delete elements from rear end 
{
    NODE cur;
    NODE prev;
    cur=first;
    prev=NULL;
    if(first==NULL)    // Check if List is Empty
    {
        printf("The list is empty!\n");
        return NULL;
    }
    else if(first->link==NULL)
    {
        printf("Deleted Element is %d\n",first->info);
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
        printf("Deleted Element is %d\n",cur->info);
        free(cur);   // Element deleted
        prev->link=NULL;
        return first;
    }
}
void main()
{     // Start main()
    int ch;
    while(1)
    {
        printf("Dequeue Menu :\n1.Insert from rear\n2.Insert from front\n3.Delete from rear\n4.Delete from front\n5.Display \n6.Exit\n\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)  // Select Operation
        {
        case 1:
            printf("Insert the item you want to insert : ");
            scanf("%d",&item);
            first=ins_rear(first,item);  // Call ins_rear function
            break;
        case 2:
            printf("Insert the item you want to insert : ");
            scanf("%d",&item);
            first=ins_front(first,item);    // Call ins_front function
            break;
        case 3:
            first=del_rear(first);    // Call del_rear function
            break;
        case 4:
            first=del_front(first);   // Call del_front function
            break;
        case 5:
            first=display(first);    // Call display function
            break; 
        case 6:
            exit(0);
        default:
            printf("Wrong Choice !\n ");
        }
    }

}   // End main()
