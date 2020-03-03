#include<stdio.h>
#include<stdlib.h>
struct node  // Define a node
{
    int info;
    struct node *llink; //left link
    struct node *rlink; //right link
};
typedef struct node *NODE;
NODE root;
NODE getnode() //function to create new node
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL) //Check if memory is full
    {
        printf("\nOut of memory ! \n");
        exit(0);
    }
    return x;
}
NODE insert(int item,NODE root) //function to insert new node
{
    NODE temp,cur,parent;
    temp=getnode();   //call getnode() function
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(root==NULL)
        return temp;  // Node inserted
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
        parent->llink=temp;  // Node inserted
    else
        parent->rlink=temp;  // Node inserted
    return root;
}
NODE search(int item,NODE root) //function to search a specified node
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
NODE delete(int item,NODE root) //function to delete specified node
{
    NODE cur,parent,suc,q;
    if(root==NULL)  // Check underflow condition
    {
        printf("\nTree doesn't exist!");
        return root;
    }
    parent=NULL;
    cur=root;
    while(cur!=NULL)
    {
        if(cur->info==item)
            break;
        parent=cur;
        if(cur->info>item)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(cur==NULL)
    {
        printf("\nItem not found");
        return root;
    }
    if(cur->llink==NULL)
        q=cur->rlink;
    else if(cur->rlink==NULL)
        q=cur->llink;
    else
    {
        suc=cur->rlink;
        while(suc->llink!=NULL) //finding the inorder successor
            suc=suc->llink;
        q=cur->rlink;
        suc->llink=cur->llink;
    }
    if(q==NULL)
    {
        free(cur);
        return root;
    }
    else if(parent->llink==cur) //attaching to the parent
        parent->llink=q;
    else
        parent->rlink=q;
    free(cur);
    return root;
}
void inorder(NODE root) //function for inorder traversal
{
    if(root==NULL)
        return;
    inorder(root->llink); //call inorder() function
    printf("->%d",root->info);
    inorder(root->rlink); //call inorder() function
}
void preorder(NODE root) //function for preorder traversal
{
    if(root==NULL)
        return;
    printf("->%d",root->info);
    preorder(root->llink); //call preorder() function
    preorder(root->rlink); //call preorder() function
}
void postorder(NODE root) //function for postorder traversal
{
    if(root==NULL)
        return;
    postorder(root->llink);  //call postorder() function
    postorder(root->rlink);  //call postorder() function
    printf("->%d",root->info); 
}
void main() //start main()
{
    int n,item;
    NODE s;
    while(1)
    {
        printf("\nBST : \n1. Insert a node\n2. Search a node\n3. Delete of node\n4. InOrder Traversal\n5. PreOrder Traversal\n6. PostOrder Traversal\n7.Exit\n Enter your choice : ");
               scanf("%d",&n);
               switch(n)
               {
                   case 1 :printf("Enter the item that you want to insert : ");
                   scanf("%d",&item);
                   root=insert(item,root); //call insert() function
                   break;
                   case 2 :printf("Enter the item that you want to search : ");
                   scanf("%d",&item);
                   s=search(item,root); //call search() function
                   if(s==NULL)
                        printf("The element is not present in the list");
                   else
                        printf("The element %d is found!\n",s->info);
                        break;
                    case 3 :printf("Enter the item that you want to delete : ");
                    scanf("%d",&item);
                    root=delete(item,root); //call delete() function
                    if(root == NULL)
                        printf("Item is not present in the tree.\n");
                    else
                        printf("The element has been deleted.\n");
                    break;
                    case 4 :inorder(root); //call inorder() function
                        printf("\n");
                    break;
                    case 5 :preorder(root); //call preorder() function
                        printf("\n");
                    break;
                    case 6 :postorder(root); //call postorder() function
                        printf("\n");
                    break;
                    case 7 :exit(1);
                    default : printf("\n Wrong Choice !");
                }
    }
} //end main()
