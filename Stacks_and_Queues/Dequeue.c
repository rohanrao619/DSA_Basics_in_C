#include<stdio.h>
#include<stdlib.h> 
#define MQS 20   // MQS is maximum stack size
void ins_rear(int q[],int item,int * r)   // Function to insert element from rear end
{
    if(*r==MQS-1) // Check Overflow condition
    {
        printf("Overflow!\n");
    }
    else
    {
        printf("Enter the item to be inserted : ");
        scanf("%d",&item);
        *r=*r+1;
        q[*r]=item;   // Element inserted
    }
}

void ins_front(int q[],int item,int *f, int *r)   // Function to insert element from front end
{
    if(*f==0 & *r==-1)
    {
        *r=*r+1;
        printf("Enter the item to be inserted : ");
        scanf("%d",&item);
        q[*r]=item;    // Element inserted
    }
    else if(*f!=0)
    {
        printf("Enter the item to be inserted : ");
        scanf("%d",&item);
        *f=*f-1;
        q[*f]=item;   // Element inserted
    }
    else
    {
        printf("Insertion from front is not possible!\n");
    }
}
void delete_front(int q[],int *f, int *r)   // Function to delete elements from front end 
{   int item;
    if(*f>*r) //Check if Queue is Empty
    {
        printf("Queue is empty!\n");
    }
    else
    {
        item=q[*f];
        *f=*f+1;   // Element deleted
        printf("Deleted item is %d\n",item);
    }
}
void delete_rear(int q[],int *f, int *r)  // Function to delete elements from rear end 
{
    if(*f>*r) //Check if Queue is Empty
        printf("Queue is empty");
    else
    {
        printf("Deleted item is %d\n",q[*r]);
        *r=*r-1;     // Element deleted
        if(*f>*r)
        {
            *f=0;
            *r=-1;
        }
    }
}
void display(int q[],int *f, int *r)    // Function to show elements of List
{   int i;
    if(*f>*r) //Check if Queue is Empty
    {
        printf("Queue is empty!\n");
    }
    else
    {
        for(i=*f; i<=*r; i++)
        {
            printf("%d  ",q[i]);   // Display Elements
        }
        printf("\n");
    }
}
void main()
{   int q[20],f=0,r=-1,item,i,ch;      // Start main()
    while(1)
    {
        printf("Deque Menu:\n1.Insert from rear \n2.Insert from front\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)     // Select operation
        {
        case 1:
            ins_rear(q,item,&r);    // Call ins_rear function
            break;
        case 2:
            ins_front(q,item,&f,&r);     // Call ins_front function
            break;
        case 3:
            delete_front(q,&f,&r);     // Call  delete_front function
            break;
        case 4:
            delete_rear(q,&f,&r);     // Call delete_rear function
            break;
        case 5:
            display(q,&f,&r);     // Call displayr function
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong choice!\n");
            break;
        }
    }
}       // End main()
