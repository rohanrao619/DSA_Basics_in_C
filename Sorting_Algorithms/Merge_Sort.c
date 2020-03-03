/*
	C program to implement merge sort
	time complexity: O(n*logn)
*/
//included all required header file
#include<stdio.h>
/*
	merges two subarrays 
	first subarray is a[1...m]
	second subarray is a[m+1...r]
	merged array is stored in array c
	merged array is then stored back 
	in array a in sorted mannner 
*/
void merge(int a[], int l,int m, int r){
	int c[r-l+1];
	int i=l;//for first subarray
	int j=m+1;//for second subarray
	int k=0;
	//copying data in to a temp. array c in sorted manner
	while((i<=m)&&(j<=r)){
		if(a[i]<=a[j])
			c[k++]=a[i++];
		else
			c[k++]=a[j++];				
	}
	//copying remaning elements of first subarray
	while(i<=m)
		c[k++]=a[i++];
	//copying remaning elements of second subarray
	while(j<=r)
		c[k++]=a[j++];
	int z=0;
	//copying back data into original array a
	for(z=0;z<k;z++)
		a[l+z]=c[z];		
}

/*
	this is function of mergesort
	which divides the array in subarray(left part,right part)
	and then calls merge function after dividing all array into
	its subparts  
*/
void MergeSort(int a[], int l, int r){
	if(l<r){
		int m=(l+r)/2;
		//sorting first and second havles
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main(){
	int n,i;
	printf("Enter the number of elements: \n");
	scanf("%d",&n);//size of array
	int a[n];
	printf("Enter the array elements: \n");
	//input of array elements
	for (i = 0; i < n; ++i)
		scanf("%d",&a[i]);
	//function call mergesort
	MergeSort(a,0,n-1);
	//printing the sorted array
	for(i=0;i<n;++i)
		printf("%d\t",a[i]);
	printf("\n");
	return 0;
}