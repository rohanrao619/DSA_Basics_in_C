#include<stdio.h>
#include<stdlib.h>
int choice,i,ch;
struct node // Define Node of Linked list
{
    int info;
    struct node *link;
};
struct node *START1=NULL;
struct node *START2=NULL;
struct node *START=NULL;
int count=0;
struct node* createNode() //Function to create new node
{
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node)); // Node Created
    return(n);
}
void insertNode1() //Function to insert new node in Linked list 1
{
    struct node *temp,*t;
    t=START1;
    temp=createNode();
    printf("Enter a Number : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START1==NULL)
        START1=temp;  // Node inserted
    else
    {
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;   // Node inserted
    }
}
void insertNode2() //Function to insert new node in Linked List 2
{
    struct node *temp,*t;
    t=START2;
    temp=createNode();
    printf("Enter a Number : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START2==NULL)
        START2=temp;   // Node inserted
    else
    {
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;   // Node inserted
    }
}
struct node *concatenate() //Function to concatenate 2 Linked Lists
{
    struct node *t;
    if(START1==NULL)
    {
        printf("The first linked list is empty");
        return(START2);
    }
    if(START2==NULL)
    {
        printf("The second linked list is empty");
        return(START1);
    }
    else
    {
        t=START1;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=START2;
        return(START1);
    }
}
void deleteNode() //Function to delete a node whose info part is specified
{
    struct node *r,*p;
    if(START1==NULL)  // Check if list is empty
        printf("List Is Empty\n");
    else
    {
        int item;
        r=START1;
        p=START1;
        printf("Enter an item : ");
        scanf("%d",&item);
        while(r->info!=item)
        {
            p=r;
            r=r->link;
        }
        p->link=r->link;
        free(r); // Element deleted

    }
}
void viewList1() //Function to display items in Linked List 1
{
    struct node *t;
    if(START1==NULL) // Check if list is empty
    {
        printf("List Is Empty\n");
    }
    else
    {
        t=START1;
        while(t!=NULL)
        {
            printf("%d ",t->info);   // Display Elements
            t=t->link;
        }
    }
}
void viewList2() //Function to display items in Ordered Linked List
{
    struct node *t;
    if(START==NULL) // Check if list is empty
    {
        printf("List Is Empty\n");
    }
    else
    {
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->info);     // Display Elements
            t=t->link;
        }
    }
}
int length() //Function to calculate length of the linked list
{
    struct node *t;
    t=START1;
    while(t->link!=NULL)
    {
        t=t->link;
        count++;
    }
    return(count);
}
int reverseList() //Function to reverse the linked list
{
    struct node *p,*t,*r;
    p=t=NULL;
    r=START1;
    while(r!=NULL)
    {
        t=r->link;
        r->link=p;
        p=r;
        r=t;
    }
    START1=p;
}
void insertNode3() //Function to insert a node whose info part is specified
{
    struct node *temp,*t;
    t=START1;
    temp=createNode();
    printf("Enter a Number To be Inserted : ");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START1==NULL)  // Check if list is empty
        printf("List is empty");
    else
    {
        int item;
        printf("Enter the item (where to be inserted) : ");
        scanf("%d",&item);
        while(t->info!=item)
        {
            t=t->link;
        }
        temp->link=t->link;
        t->link=temp;
    }
}
void InsertOrdered() //Function to create an ordered linked list
{
    struct node *p,*temp;
    temp=createNode();
    printf(" Enter a number : ");
    scanf("%d",&temp->info);
    if(START==NULL || START->info >= temp->info)
    {
        temp->link=START;
        START=temp;
    }
    else
    {
        struct node *t;
        t=START;
        while(t->link!=NULL && t->link->info < temp->info)
        {
            t=t->link;
        }
        temp->link=t->link;
        t->link=temp;
    }
}
int main()
{   // Start main()
    int k;
    char ch;
    while(1)
    {   printf("\n\n1. Insert Node");
        printf("\n2. Concatenate");
        printf("\n3. Length Of Linked List");
        printf("\n4. Reverse  the List");
        printf("\n5. Delete A Node (Specify Info Part)");
        printf("\n6. Insert A Node (Specify Info Part)");
        printf("\n7. Ordered Linked List");
        printf("\n8. Display");
        printf("\n9. Quit");
        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch) //Select operation
        {
        case 1:
            insertNode1(); // Call insertNode1() function
            break;
        case 2:
            while(1)
            {
                printf("1. Insert Node On 2nd Linked List\n");
                printf("2. Concatenate\n");
                printf("\nEnter Your Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                    insertNode2();  // Call insertNode2() function
                    break;
                case 2:
                    concatenate();  // Call concatenate() function
                    i=2;
                    break;
                }
                if(i==2)
                    break;
            }
            break;
        case 3:
            printf("%d",length()+1);  // Call length() function
            break;
        case 4:
            reverseList(); // Call reverseList() function
            break;
        case 5:
            deleteNode();  // Call deleteNode() function
            break;
        case 6:
            insertNode3();  // Call insertNode3() function
            break;
        case 7:
            InsertOrdered();  // Call InsertOrdered() function
            break;
        case 8:
            printf("\nChoice\n1. Display 1st Linked List\n2. Display Ordered Linked List\nEntered your choice : ");
            scanf("%d",&k);
            if(k==1)
                viewList1();  // Call viewList1() function
            else
                viewList2();  // Call viewList2() function
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("invalid entry");
        }
    }
    return 0;
}   // End main()