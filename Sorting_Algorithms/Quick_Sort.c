/* 
	C program to implement quick sort
	time complexity: O(n*logn)
		 worst case: O(n*n) {only when input is ascending or descending order} 
*/
//included all required header file
#include<stdio.h>
/*
	swap is a utility user defined function 
	that is used to swap two values the
	a and b using pointer and a temp. variable c
*/
void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}
/*
	
*/
int partition(int a[], int l, int r){
	int pivot=a[l];
	int i=l;
	int j=r+1;
	while(i<=j){
		do{
			i++;
		}while(pivot>a[i]);
		
		do{
			j--;
		}while(pivot<a[j]);
		
		if(i<j)
			{
				swap(&a[i],&a[j]);
			}
	}
	
	swap(&a[l],&a[j]);
	return j;
			
}


void QuickSorts(int a[], int l, int r){
	if(l<r){
		int k=partition(a,l,r);
		QuickSorts(a,l,k-1);
		QuickSorts(a,k+1,r);
	}
}

void QuickSort(int a[], int l, int r){
	a[r+1]=10000000;
	QuickSorts(a,l,r);	
}


int main()
{
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int a[n+1];
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;	
}
