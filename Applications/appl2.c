#include <stdio.h>
#include <string.h>

// Define structure for Product
struct Product {
    char name[50];
    float price;
};

// Function to swap two products
void swap(struct Product *a, struct Product *b) {
    struct Product temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function (for QuickSort)
int partition(struct Product arr[], int low, int high) {
    float pivot = arr[high].price;  // Pivot = last element's price
    int i = low - 1;
    int j;
    for (j = low; j < high; j++) {
        if (arr[j].price < pivot) { // Ascending order
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(struct Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to display products
void display(struct Product arr[], int n) {
    printf("\n%-20s%-10s\n", "Product Name", "Price");
    printf("------------------------------\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%-20s$%.2f\n", arr[i].name, arr[i].price);
    }
}

int main() {
    int n,i;

    printf("Enter number of products: ");
    scanf("%d", &n);
    getchar(); // consume newline

    struct Product products[n];

    // Input product details
    for (i = 0; i < n; i++) {
        printf("\nEnter name of product %d: ", i + 1);
        fgets(products[i].name, sizeof(products[i].name), stdin);
        products[i].name[strcspn(products[i].name, "\n")] = '\0'; // remove newline

        printf("Enter price of product %d: $", i + 1);
        scanf("%f", &products[i].price);
        getchar(); // consume newline
    }

    printf("\n--- Product List Before Sorting ---");
    display(products, n);

    // Sort products by price using QuickSort
    quickSort(products, 0, n - 1);

    printf("\n--- Product List After Sorting by Price (Ascending) ---");
    display(products, n);

    return 0;
}

