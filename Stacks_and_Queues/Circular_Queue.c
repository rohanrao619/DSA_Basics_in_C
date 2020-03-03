#include<stdio.h>
#include<stdlib.h>
#define qs 5   // qs is Circular Queue Size
void insertq(int item, int *rear, int *q, int *count)  // Fuction to insert element in Circular Queue
{
    if(*count==qs)   // Check overflow condition
    {
        printf("Overflow!\n");  
        return;
    }
    *rear = (*rear+1) %qs;
    q[*rear] = item;    // Element inserted
    (*count) ++;
}
int deleteq(int* front, int q[], int*count)   // Function to delete element from Circular Queue
{
    int item;
    if((*count)==0)   // Check underflow condition
        return -1;
    item=q[*front];
    *front=(*front+1)%qs;     // Element deleted
    *count=*count-1;
    return item;
}
void display(int front, int q[], int count)    // Function to display elements in Circular Queue
{
    int i,f=front;
    if(count==0)    //  Check if Circular Queue is Empty
    {
        printf("No elements in the Queue!\n");
        return;
    }
    for(i=1; i<=count; i++)
    {
        printf("%d ",q[f]);   // Display Circular Queue elements
        f=(f+1)%qs;
    }
}
void main()    // Start main()
{
    int rear=-1, front=0, q[qs], item, count=0;
    int ch;
    for(;;)
    {
        printf("Circular Queue Menu: \n1. Insert \n2. Delete \n3. Display \n4. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)   // Select Operation
        {
        case 1:
            printf("Enter element to be inserted : ");
            scanf("%d", &item);
            insertq(item,&rear,q,&count);   // Call insertq function 
            break;
        case 2:
            item=deleteq(&front,q,&count);    // Call deleteq function 
            if(item==-1)
                printf("Queue is Empty!");
            else
                printf("The deleted item is: %d\n",item);
            break;
        case 3:
            display(front,q,count);     // Call display function 
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
}      // End main()

