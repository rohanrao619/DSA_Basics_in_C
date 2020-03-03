#include <stdio.h>
#define MAS 100            // Maximum Array size
 
int main()
{                // Start main()
   int Arr[MAS], n, i, j, k ,l=0, temp,gap;
   label:
   printf("Enter number of elements in the Array (max %d) : ",MAS);
   scanf("%d", &n);
   if(n<1||n>100)
   { printf("Please enter a valid Array size ! \n");
   goto label;
   }
 
   printf("Enter Array elements : ", n);
 
   for ( i = 0 ; i < n ; i++ )         // Take input
      scanf("%d", &Arr[i]);
 
for(gap=n/2; gap > 0; gap /= 2)       // Loop to perform Shell sort
    { l+=1;
	    for(i=gap;i< n; i += 1)
        {
            temp = Arr[i];           
            for (j = i; j >= gap && Arr[j - gap] > temp; j -= gap)
                Arr[j] = Arr[j - gap];
            Arr[j] = temp;
        }
        printf("The Array after iteration %d is : ",l);
        for ( k = 0 ; k < n ; k++ )                      //  Show intermediate Arrays
         printf("%d  ", Arr[k]);  
        printf("\n");
    }

   printf("\nThe Sorted Array in ascending order is : ");
 
   for ( i = 0 ; i < n ; i++ )           // Display Sorted Array
      printf("%d  ", Arr[i]);
 
   return 0;
}           // End main()

