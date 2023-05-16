#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    // Store the value at 'a' in a temporary variable
    int temp = *a;
    // Assign the value at 'b' to 'a'
    *a = *b;
    // Assign the value stored in the temporary variable to 'b'
    *b = temp;
}

// Function to adjust the heap
void heapify(int arr[], int n, int i) {
    // Assume the current element is the largest
    int largest = i;
    // Calculate the indices of the left and right child nodes
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is larger than the current largest element
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If the right child is larger than the current largest element
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If the largest element is not the current element
    if (largest != i) {
        // Swap the current element with the largest element
        swap(&arr[i], &arr[largest]);

        printf("Heapify: ");
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");

        // Recursively adjust the heap for the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap Sort algorithm
void heapSort(int arr[], int n) {
    // Build the initial heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Perform heap sort
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root (maximum element) to the end
        swap(&arr[0], &arr[i]);

        printf("Swap: ");
        for (int j = 0; j < n; j++)
            printf("%d ", arr[j]);
        printf("\n");

        // Adjust the heap for the reduced array
        heapify(arr, i, 0);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {9, 4, 2, 7, 5, 1, 8, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, n);
    
    // Sort the array using Heap Sort algorithm
    heapSort(arr, n);
    
    printf("Array after Heap Sort: ");
    printArray(arr, n);

    return 0;
}
