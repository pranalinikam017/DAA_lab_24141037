#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain min-heap property
void heapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min heap
void buildMinHeap(int arr[], int n) {
	int i;
    for ( i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to extract the minimum element from the heap
int extractMin(int arr[], int *n) {
    int root = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// Function to insert a new element into the heap
void insertHeap(int arr[], int *n, int key) {
    (*n)++;
    int i = *n - 1;
    arr[i] = key;
    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to calculate minimum cost of optimal merge pattern
int optimalMerge(int files[], int n) {
    buildMinHeap(files, n);
    int totalCost = 0;

    while (n > 1) {
        int first = extractMin(files, &n);
        int second = extractMin(files, &n);

        int cost = first + second;
        totalCost += cost;

        insertHeap(files, &n, cost);
    }

    return totalCost;
}

int main() {
    int n,i;
    printf("Enter number of files: ");
    scanf("%d", &n);

    int files[n];
    printf("Enter the sizes of files: ");
    for (i = 0; i < n; i++)
        scanf("%d", &files[i]);

    int minCost = optimalMerge(files, n);
    printf("\nMinimum total cost for optimal merge pattern = %d\n", minCost);

    return 0;
}

