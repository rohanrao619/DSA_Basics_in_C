#include<stdio.h>
#include<stdlib.h>
int c=0,clf=0;
struct node  // Define new node
{
    int info;
    struct node *llink; //left link
    struct node *rlink;  //right link
};
typedef struct node *NODE;
NODE root;
NODE getnode() //function to create new node
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node)); 
    if(x==NULL)
    {
        printf("\nOut of memory !");
        exit(0);
    }
    return x;
}
NODE insert(int item,NODE root) //function to insert new node
{
    NODE temp,cur,parent;
    temp=getnode(); //call getnode() function
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        return temp;
    cur=root;
    while(cur!=NULL)
    {
        parent = cur;
        if(cur->info>item)
            cur=cur->llink;
        else if(cur->info<item)
            cur=cur->rlink;
    }
    if(parent->info>item)
        parent->llink=temp;
    else
        parent->rlink=temp;
    return root;
}
void count(NODE root) //function to count no. of nodes
{
    if(root == NULL)
        return;
    count(root->llink);
    c++;
    count(root->rlink);
}
void countlf(NODE root)  //function to count no. of leaf nodes
{
    if(root == NULL)
        return;
    countlf(root->llink); //call countlf() function
    if(root->llink==NULL & root->rlink==NULL)
        clf++;
    countlf(root->rlink); //call countlf() function
}
void range(NODE root) //function to find range of BST
{
    NODE cur=root;
    int max,min,range;
    while(cur->llink!=NULL)
        cur=cur->llink;
    min=cur->info;
    cur=root;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    max=cur->info;
    printf("\nThe maximum element : %d",max);
    printf("\nThe minimum element : %d",min);
    range=max-min;
    printf("\nThe range of the BST : %d",range);
}
NODE search(int item,NODE root) //function to search an element in BST
{
    NODE cur;
    cur=root;
    while(cur!=NULL)
    {
        if(cur->info==item)
            break;
        else if(cur->info>item)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    return cur;
}
int height(NODE root) //function to find height of BST
{
    if(root==NULL)
        return -1;
    else
        return 1+max(height(root->llink),height(root->rlink)); //call max() function
}
int max(int a,int b) //function to find max of 2 input
{
    if(a>b)
        return a;
    else
        return b;
}

void main() //start main()
{
    int ch=1,n,item,h,r;
    NODE s;
    while(ch)
    {
        printf("\n OPERATIONS : \n1.Insert a node\n2.Count the number of nodes\n3.Count the number of leaf nodes\n4.Find range\n5.Find height of a node\n Make your choice : ");
               scanf("%d",&n);
               switch(n)
           {
               case 1 :printf("\nEnter the item that you want to insert : ");
               scanf("%d",&item);
               root=insert(item,root); //call insert() function
               break;
               case 2 :count(root);  //call count() function
               printf("\nThe number of nodes in the BST is %d",c);
               c=0;
               break;
               case 3 :countlf(root); //call the countlf() function
               printf("\nThe number of leaf nodes in the BST is %d",clf);
               clf=0;
               break;
               case 4 :range(root);  //call the range() function
                   break;
               case 5 :printf("\nEnter the info of the node whom you want the height of : ");
                                      scanf("%d",&item);
                                      s=search(item,root);  //call the search() function
                                      if(s==NULL)
                                      printf("\nItem is not present in the tree!");
                                      else
                {
                    h=height(s);  //call the height() function
                    printf("\nThe height of the node is %d ",h);
                }
        break;
        case 6: exit(1);
        default : printf("\nWrong choice ! ");
        }
    }
} //end main()

