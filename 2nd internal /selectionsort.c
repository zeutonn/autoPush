#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Straight Selection Sort
void straightSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i+1;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        printf("Swapping %d and %d\n", arr[i], arr[minIndex]);
        swap(&arr[minIndex], &arr[i]);
        printf("Array after swapping: ");
        printArray(arr, n);
        printf("\n");
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

    printf("Original Array: ");
    printArray(arr, n);
    printf("\n");

    // Straight Selection Sort
    straightSelectionSort(arr, n);

    printf("\nArray after Selection Sort: ");
    printArray(arr, n);

    return 0;
}
