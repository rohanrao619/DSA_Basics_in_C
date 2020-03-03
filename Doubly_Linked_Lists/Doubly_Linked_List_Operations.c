#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
struct node // Define node
{
    int info;
    struct node *llink; //left link
    struct node *rlink; //right link
};
typedef struct node *NODE;
NODE header; //header node
int item;
NODE getnode() //function to create new node
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node)); 
    if(x==NULL)
    {
        printf("Out of memory! /n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE header,int item) //function to insert from front end
{
    NODE first,temp;
    temp=getnode();   //call getnode() function
    temp->info=item;
    first=header->rlink;
    header->rlink=temp;
    temp->rlink=first;
    temp->llink=header;
    return header;
}
NODE insert_back(NODE header,int item)    //function to insert from rear end
{
    NODE temp,cur;
    temp=getnode();    //call getnode() function
    temp->info=item;
    temp->rlink=NULL;
    cur=header;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    return header;
}
int delete_front(NODE header) //function to delete from front end
{
    NODE cur,next;
    int t;
    if(header->rlink==NULL)    // Check underflow condition
        return -1;
    cur=header->rlink;
    next=cur->rlink;
    header->rlink=next;
    next->llink=header;
    t=cur->info;
    free(cur);
    return t;
}
int delete_back(NODE header) //function to delete from rear end
{
    NODE prev,cur;
    int t;
    if(header->rlink==NULL)    // Check underflow condition
        return -1;
    cur=header->rlink;
    prev=NULL;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur=cur->rlink;
    }
    prev->rlink=NULL;
    t=cur->info;
    free(cur);
    return t;
}
NODE display(NODE header) //function to display the list
{
    NODE cur;
    if(header->rlink==NULL)   // Check underflow condition
    {
        printf("The list is empty ! \n");
        return header;
    }
    cur=header->rlink;
    printf("The elements are : \n");
    while(cur!=NULL)
    {
        printf("%d\n",cur->info); //print the elements
        cur=cur->rlink;
    }
    return header;
}
int main()        //start main()
{
    header=getnode();
    header->info=1;
    header->rlink=NULL;
    header->llink=NULL;
    int ch,c;
    while(1)
    {
        printf("\nDoubly Linked List :\n1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Quit\n");
               scanf("%d",&ch);
               switch(ch) 
           {
               case 1 :printf("\nInsert the element to be inserted: ");
               scanf("%d",&item);
               header=insert_front(header,item); //call insert_front() function
               break;
               case 2 :printf("\nInsert the element to be inserted : ");
               scanf("%d",&item);
               header=insert_back(header,item); //call insert_back() function
               break;
               case 3: c=delete_front(header); //call delete_front() function
               if(c==-1)
               printf("\nThe list is empty ! \n");
               else
               printf("\nThe deleted element is : %d\n",c);
               break;
               case 4 :c=delete_back(header); //call delete_back() function
               if(c==-1)
               printf("\nThe list is empty ! \n");
               else
               printf("\nThe deleted element is : %d",c);
               break;
               case 5 :header=display(header);//call display() function
               break;
               case 6 : exit(1);
               default: printf("\nWrong Choice ! ");
           }
    }
    return 0;
}        //end of main()
