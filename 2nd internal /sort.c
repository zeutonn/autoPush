#include<stdio.h>

/*
void sort (int* a, int* b){
	int temp = a*; 
	a*= b*;
	b* = temp;
}
*/
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
 	int i,j;
 	for (i=0; i<n-1; i++){
 		int min_index=i;
 		for (j=i+1; j<n; j++){
 			if (arr[j]<arr[min_index])
 				min_index=j;
 		}
 		swap (&arr[min_index], &arr[i]);
 	}
 }
 
 void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{

	int arr[] = {9, 4, 2, 7, 5, 1, 8, 3, 6};
	int n= sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	printf("Array after Selection Sort: ");
	printArray(arr, n);
return 0;
}
