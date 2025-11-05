#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int size, int id) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == id)
            return mid;  // Found

        if (arr[mid] < id)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1;  // Not found
}

int main() {
    int n, i, id;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int studentIDs[n];

    printf("Enter %d student IDs in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &studentIDs[i]);
    }

    printf("Enter student ID to search: ");
    scanf("%d", &id);

    int result = binarySearch(studentIDs, n, id);

    if (result != -1)
        printf("? Student ID %d found at index %d.\n", id, result);
    else
        printf("? Student ID %d not found in the list.\n", id);

    return 0;
}

