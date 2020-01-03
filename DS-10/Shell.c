#include <stdio.h>
  

int shellSort(int arr[], int n) 
{ 
    
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
       
        for (int i = gap; i < n; i += 1) 
        { 
           
            int temp = arr[i]; 
  
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
  
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        printf("%d ",arr[i]); 
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
  
    shellSort(arr, n); 
  
    printf("Sorted array is \n"); 
    printArray(arr, n); 
  
    return 0; 
}