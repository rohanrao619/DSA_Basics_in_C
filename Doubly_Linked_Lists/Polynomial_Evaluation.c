#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct NODE    // Define node
{
	int co,px,py;
	struct NODE *link;
};
typedef struct NODE* node;
node start=NULL;
node create_node()   // Function to Create node
{
	node temp= (node)malloc(sizeof(struct NODE));
	if(temp==NULL)                 // Check if Memory is full
	{ printf("No memory left!\n");
	  exit(1);
	}
	temp->link=NULL;
	return temp;
 } 
 
 void insert_node()   // Function to insert term in the polynomial
 {
 	node tmp,cur=start;
 	tmp=create_node();
 	printf("Enter coefficient of the term : ");
 	scanf("%d",&(tmp->co));
 	printf("Enter power of x in the term : ");
 	scanf("%d",&(tmp->px));
 	printf("Enter power of y in the term : ");
 	scanf("%d",&(tmp->py));
 	if(start==NULL)
 	start=tmp;
 	else
 	{ 
	  while(cur->link!=NULL)
 	  {
 	  	cur=cur->link;
	   }
 	  cur->link=tmp;  // Node inserted
	}
}
 void evaluate()    // function to evaluate the polynomial
 {
 	node cur;
 	int sum=0,tmp,x,y;
 	if(start==NULL)   // Check underflow Condition
 	{
 		printf("NO Terms!");
 		return;
	 }
	printf("Enter value of x : ");
 	scanf("%d",&x); 
 	printf("Enter value of y : ");
 	scanf("%d",&y);
	cur=start;
	while(cur!=NULL)
	{
		tmp=(cur->co)*(pow(x,cur->px))*(pow(y,cur->py));
		sum+=tmp;
		cur=cur->link;
	 } 
	printf("The result is : %d",sum);  // Print Result
 }

void main()
{               // Start main
	int ch;
	while(1)
	{   printf("\n1.Enter term\n2.Evaluate polynomial\n3.Clear the polynomial\n4.Exit\n\nEnter your choice : ");
	    scanf("%d",&ch);
		switch(ch)
		{
			case 1 : insert_node();  // Call insert_node() function
			         break;
			case 2 : evaluate(); // Call evaluate() function
					 break;
			case 3 : free(start); // Clear the polynomial terms
					 start=NULL;
			         break;
			case 4 : exit(1);
			default : printf("Wrong Choice ! \n");
			          break;		         
		}
	}
 }   // End main
