#include<stdio.h>
#include<stdlib.h>
struct node     // Define Node of Linked List
{
    int info;
    struct node *link;
};
int item;
struct node *node;
struct node *first=NULL;
struct node *header;
struct node *getnode()    // Fuction to Create new Node
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));   // New Node created
    if(temp==NULL)     // Check if Memory is full
    {
        printf("No Memory left!\n");
        exit(0);
    }
    return temp;
}
struct node *insert_front(struct node *header)  // Function to insert element from front end
{
    int item;
    struct node *temp;
    temp=getnode();
    printf("Enter The Element to be inserted : ");
    scanf("%d",&item);
    temp->info=item;
    first=header->link;
    temp->link=first;
    header->link=temp;   // Element inserted
    return header;
}
struct node *insert_rear(struct node *header)   // Function to insert element from rear end
{
    struct node *temp,*cur;
    temp=getnode();
    printf("Enter The Element to be inserted : ");
    scanf("%d",&item);
    temp->info=item;
    temp->link=NULL;
    if(header==NULL)    // Check if List is Empty
        return temp;
    else
    {
        cur=header;
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=temp;    // Element inserted
        return header;
    }
}
struct node *delete_front(struct node *header)  // Function to delete elements from front end 
{
    struct node *first,*second;
    if(header->link==NULL)    // Check if List is Empty
    {
        printf("List is empty!\n");
        return NULL;
    }
    first=header->link;
    second=first->link;
    header->link=second;
    printf("Item deleted is %d\n",first->info);
    free(first);   // Element deleted
    return header;
}
struct node *delete_rear(struct node *header)  // Function to delete elements from rear end 
{
    struct node *cur,*prev;
    if(header->link == NULL)   // Check if List is Empty
    {
        printf("List is empty!\n");
        return header;
    }
    prev = header;
    cur = header->link;
    while(cur -> link != NULL)
    {
        prev = cur;
        cur = cur ->link;
    }
    printf("Item deleted is %d\n", cur-> info);
    free(cur);    // Element deleted
    prev -> link = NULL;
    return header;
}
struct node *display(struct node *header)   // Function to show elements of List
{
    struct node *cur;
    cur=header->link;
    if(header->link==NULL)    // Check if List is Empty
    {
        printf("List is empty!\n");
        return NULL;
    }
    else
    {
        printf("The elements in the list are :  ");
        while(cur->link!=NULL)
        {
            printf("%d  ",cur->info);  // Display elements
            cur=cur->link;
        }
        printf("%d\n",cur->info);   // Display element
        return header;
    }
}

int menu()  // Function to Show Menu
{    
    int ch;
    printf("Singly linked list :\n1.Insert from front\n2.Insert from rear\n3.Delete from front\n4.Delete from rear\n5.Display \n6.Exit\n\nEnter your choice : ");
    scanf("%d",&ch);
    return(ch);
}
void main()
{  // Start main()
    header=getnode();
    header->link=first;
    while(1)
    {
        switch(menu())  // Select Operation
        {
        case 1:
            insert_front(header); // Call insert_front function
            break;
        case 2:
            insert_rear(header);  // Call insert_rear function
            break;
        case 3:
            delete_front(header);  // Call delete_front function
            break;
        case 4:
            delete_rear(header);   // Call delete_rear function
            break;
        case 5:
            display(header);   // Call display function
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong Choice!\n");
        }
    }

}  // End main()

