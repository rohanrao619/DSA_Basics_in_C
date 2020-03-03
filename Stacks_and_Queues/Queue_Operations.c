#include<stdio.h>
#include<stdlib.h>
#define qs 10    // qs is Queue Size
void Insert_rear(int item, int *rear, int q[])    // Fuction to insert element in Queue
{
    if(*rear==qs-1)   // Check overflow condition
    {
        printf("Overflow!\n");
        return;
    }
    *rear=*rear+1;
    q[*rear]=item;   // Element inserted in Queue
}
int Delete_front(int *front, int *rear, int q[])    // Fuction to delete element from Queue
{
    if(*front>*rear)     // Check underflow condition
        return -1;
    return q[(*front)++];   // Element deleted from Queue
}
void Display(int front, int rear, int q[])      // Fuction to display elements in Queue
{
    int i;
    if(front>rear)   // Check if Queue is Empty
    {
        printf("Queue is empty!\n");
        return;
    }
    for(i=front; i<=rear; i++)
        printf("%d  ",q[i]);
    printf("\n");   // Display Queue elements
}
void main()
{         // Start main()
    int ch,item,front,rear,q[qs];
    front=0;
    rear=-1;
    for(;;)
    {
        printf("Queue Menu: \n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)   // Select Operation
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d",&item);
            Insert_rear(item,&rear,q);    // Call Insert_rear function 
            break;
        case 2:
            item=Delete_front(&front,&rear,q);  // Call Delete_front function 
            if(item==-1)
                printf("Queue is empty! \n");
            else
                printf("Deleted item is : %d \n",item);
            break;
        case 3:
            Display(front,rear,q);    // Call Display function
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice ! \n");
	    break;
        }
    }
}     // End main()
