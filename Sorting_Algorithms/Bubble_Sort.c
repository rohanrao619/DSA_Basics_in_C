#include <stdio.h>
#define MAS 100   // Maximum Array size
 
int main()
{            // Start main()

   int Arr[MAS], n, i, j, k , temp;
   label:
   printf("Enter number of elements in the Array (max %d) : ",MAS);
   scanf("%d", &n);
   if(n<1||n>100)
   { printf("Please enter a valid Array size ! \n");
   goto label;
   }
 
   printf("Enter Array elements : ", n);
 
   for ( i = 0 ; i < n ; i++ )   // Take input
      scanf("%d", &Arr[i]);
 
  for (i = 0 ; i < ( n - 1 ); i++)   // Loop to perform Bubble sort
  {
    for (j = 0 ; j < n - i - 1; j++)
    {
      if (Arr[j] > Arr[j+1]) 
      {
        temp       = Arr[j];
        Arr[j]   = Arr[j+1];
        Arr[j+1] = temp;
      }
    }
    printf("The Array after iteration %d is : ",i+1);
 
    for ( k = 0 ; k < n ; k++ )   //  Show intermediate Arrays
      printf("%d  ", Arr[k]);  
    printf("\n");
  }
 
   printf("\nThe Sorted Array in ascending order is : ");
 
   for ( i = 0 ; i < n ; i++ )        // Display Sorted Array
      printf("%d  ", Arr[i]);
 
   return 0;
}     // End main()
