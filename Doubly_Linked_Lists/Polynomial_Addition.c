#include<stdio.h>
#include<stdlib.h>

struct node    // Define a node
{
int cf, px, py, pz;
struct node *link;
};
typedef struct node* NODE;

NODE getnode()  // Function to Create node
{
NODE x;
x = (NODE) malloc(sizeof(struct node)); 
if(x == NULL)
{
printf("\nOut of memory!\n");
exit(0);
}
return x;
}
NODE insert_rear(int cf, int px, int py, int pz, NODE head)   // Function to insert term in polynomial
{
NODE cur, temp;
temp=getnode();  // Call getnode() function
temp->cf=cf;
temp->px=px;
temp->py=py;
temp->pz=pz;
cur=head->link;
while(cur -> link != NULL)
{
cur = cur ->link;
}
cur->link=temp;  // Term inserted
temp-> link = NULL;
return head;
} 

NODE read_poly(NODE head)  // FUnction to take input
{
int cf, px, py, pz,ch;

while(1)
{
printf("\nEnter cf, px, py, pz : ");
scanf("%d%d%d%d",&cf, &px, &py, &pz);
head=insert_rear(cf, px, py, pz, head);
printf("\n Want to enter more terms ? ( Enter 1 for yes ) ");
scanf("%d",&ch);
if(ch!=0)
return;
}
}
void display(NODE head)  // Function to display polynomial
{
NODE temp;
if(head->link==NULL)
{
printf("\n Polynomial does not exist ! \n");
return;
}
temp=head->link;
while(temp!=NULL)
{
if(temp->cf<0)
printf("%d", temp->cf);
else
printf("+%d",temp->cf);
if(temp->px !=0) printf("x^%d", temp->px);
if(temp->py !=0) printf("y^%d", temp->py);
if(temp->pz !=0) printf("z^%d", temp->pz);
temp=temp->link;
}
printf("\n");
}

NODE search(NODE p1, NODE h2)   // Function to search for a partical term in polynomail
{
int cf1, cf2, px1, px2, py1, py2, pz2, pz1;
NODE p2;
cf1=p1->cf; px1=p1->px; py1=p1->py; pz1=p1->pz;
p2=h2->link;
while(p2!=h2)
{
cf2=p2->cf; px2=p2->px; py2=p2->py; pz2=p2->pz;
if(px1==px2 && py1==py2 && pz1==pz2)
break;
p2=p2->link;
}
return p2;
}
NODE copy_poly(NODE h2, NODE h3)   // Function to copy one polynomial into other
{
int cf2, px2, py2, pz2;
NODE p2;
p2=h2->link;
while(p2!=h2)
{
if(p2->cf!=-999)
{
cf2=p2->cf; px2=p2->px; py2=p2->py; pz2=p2->pz;
h3=insert_rear(cf2, px2, py2, pz2, h3);
}
p2=p2->link;
}
return h3;
}
NODE add_poly(NODE h1, NODE h2, NODE h3) // FUnction to add 2 polynomials
{
int cf1, px1, py1, pz1, sum;
NODE p1, p2;
p1=h1->link;
while(p1!=h1)
{
cf1=p1->cf; px1=p1->px; py1=p1->py; pz1=p1->pz;
p2=search(p1, h2);  // Call search() function
if(p2!=h2)
{
sum=cf1+p2->cf;
h3=insert_rear(sum, px1, py1, pz1, h3); // Call insert_rear() function
p2->cf=-999;
}
else
h3=insert_rear(cf1, px1, py1, pz1, h3);  // Call insert_rear() function
p1=p1->link;
}
h3=copy_poly(h2, h3);  // Call copy_poly() function
return h3;
}


void main()
{           // start main()
NODE h1, h2, h3;
h1=getnode(); h2=getnode(); h3=getnode();
h1->link=h1; h2->link=h2; h3->link=h3;
printf("\nEnter the first polynomial : ");
h1=read_poly(h1);   // Call read_poly() function
printf("\nEnter the second polynomial : ");
h2=read_poly(h2);   // Call read_poly() function
printf("\nPolynomial 1 is : "); display(h1);
printf("\nPolynomial 2 is : "); display(h2);
h3=add_poly(h1, h2, h3);   // Call add_poly() function
printf("\nAddition of given two polynomial is : ");
display(h3);    // Call display() function
}   // End main()
