#include <stdio.h>
#include <limits.h>

#define MAX 100  // Maximum number of cities

// Function to find the vertex with minimum key value not included in MST
int minKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, min_index;
     int i,v;
    for (v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print MST and its total cost
void printMST(int parent[], int n, int graph[MAX][MAX], char cities[][50]) {
    int totalCost = 0,i;
    printf("\nEdges in the Minimum Spanning Tree:\n");
    printf("%-20s%-20s%-10s\n", "City1", "City2", "Cost");
    printf("---------------------------------------------\n");
    for (i = 1; i < n; i++) {
        printf("%-20s%-20s%-10d\n", cities[parent[i]], cities[i], graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("\nTotal minimum cost to connect all cities: %d\n", totalCost);
}

// Function to construct MST using Prim's algorithm
void primMST(int n, int graph[MAX][MAX], char cities[][50]) {
    int parent[MAX];  // Array to store MST
    int key[MAX];     // Key values used to pick minimum weight edge
    int mstSet[MAX];  // To represent set of vertices included in MST
    int i,count,v;
    // Initialize all keys as infinite
    for (i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;      // Start from first city
    parent[0] = -1;  // First node is root

    for (count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = 1;

        for (v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, n, graph, cities);
}

int main() {
    int n,i,j;

    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar(); // consume newline

    char cities[n][50];
    for (i = 0; i < n; i++) {
        printf("Enter name of city %d: ", i + 1);
        fgets(cities[i], sizeof(cities[i]), stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0'; // remove newline
    }

    int graph[MAX][MAX];
    printf("\nEnter adjacency matrix (0 if no direct road, cost otherwise):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    primMST(n, graph, cities);

    return 0;
}

