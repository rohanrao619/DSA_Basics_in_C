#include<stdio.h>
#define MAS 100   // Maximum Array size
#define max 25    // Maximum input Value

void countingsort(int arr[], int k, int n)  // Function to perform Count Sorting 
{
    int i, j;
    int B[MAS], C[max];
    for (i = 0; i <= k; i++)
            C[i] = 0;
    for (j =1; j <= n; j++)  // Store frequency of each distinct entry
            C[arr[j]] = C[arr[j]] + 1;
    for (i = 1; i <= k; i++)
            C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)  // Sort by storing in another Array
    {
            B[C[arr[j]]] = arr[j];
            C[arr[j]] = C[arr[j]] - 1;
    }
    printf("\nThe Sorted array is :\n");
    for(i = 1; i <= n; i++)                // Display sorted array
          printf(" %d", B[i]);
}
 
int main()
{         // start main()
    int n,i,k = 0, arr[MAS];
   label:
   printf("Enter number of elements in the Array (max %d) : ",MAS);
   scanf("%d", &n);
   if(n<1||n>100)
   { printf("Please enter a valid Array size ! \n");
   goto label;
   }
    printf("\nEnter the elements to be sorted (Enter numbers in range 0 to %d ):\n",max);
    for ( i = 1; i <= n; i++)   // Take input
    {
         scanf("%d", &arr[i]);
         if (arr[i] > k)
         {
            k = arr[i];
         }
    }
    countingsort(arr, k, n);   // call countingsort() function
    return 0;
 
}   // end main()
