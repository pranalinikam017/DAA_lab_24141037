#include <stdio.h>

// Structure to hold item details
struct Item {
    char name[50];
    float weight;
    float value;
    float ratio; // value-to-weight ratio
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio (descending order)
void sortItems(struct Item items[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Greedy Knapsack function
void greedyKnapsack(struct Item items[], int n, float capacity) {
    float totalValue = 0.0;
    float currentWeight = 0.0;
    int i;

    printf("\nSelected Items for the Truck:\n");
    printf("%-15s%-10s%-10s%-10s\n", "Item", "Weight", "Value", "Taken(%)");
    printf("----------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take the whole item
            currentWeight += items[i].weight;
            totalValue += items[i].value;
            printf("%-15s%-10.2f%-10.2f%-10.0f\n", items[i].name, items[i].weight, items[i].value, 100.0);
        } else {
            // Take fractional part of the item
            float remain = capacity - currentWeight;
            float fraction = remain / items[i].weight;
            totalValue += items[i].value * fraction;
            printf("%-15s%-10.2f%-10.2f%-10.0f\n", items[i].name, remain, items[i].value * fraction, fraction * 100);
            break;
        }
    }

    printf("\nTotal weight in truck: %.2f / %.2f\n", currentWeight, capacity);
    printf("Total profit earned: $%.2f\n", totalValue);
}

int main() {
    int n,i;
    float capacity;

    printf("Enter the number of items available: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input item details
    for (i = 0; i < n; i++) {
        printf("\nEnter name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter weight of %s (kg): ", items[i].name);
        scanf("%f", &items[i].weight);
        printf("Enter value of %s ($): ", items[i].name);
        scanf("%f", &items[i].value);

        items[i].ratio = items[i].value / items[i].weight;
    }

    printf("\nEnter maximum capacity of the truck (kg): ");
    scanf("%f", &capacity);

    // Sort by value-to-weight ratio
    sortItems(items, n);

    // Apply Greedy Knapsack
    greedyKnapsack(items, n, capacity);

    return 0;
}

