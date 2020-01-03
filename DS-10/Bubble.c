#include <stdio.h> 
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  

void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
          
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
		   {
			   int temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
		   }
} 
  

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
   int l;
	printf("Enter the size of array : ");
	scanf("%d",&l);
    int arr[l];
	printf("Enter the elements of array  : ");
	for(int i=0;i<l;i++)
	scanf("%d",&arr[i]);

    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 