#include <stdio.h>
#include <limits.h>

#define MAX 100

int n,v;// number of cities

// Function to find vertex with minimum distance not yet processed
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    
    for (v = 0; v < n; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print shortest distances from source
void printDistances(int dist[], char cities[][50], int src) {
	int i;
    printf("\nShortest distance from %s to each city:\n", cities[src]);
    printf("%-20s%-10s\n", "City", "Distance");
    printf("----------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-20s%-10d\n", cities[i], dist[i]);
    }
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int src, char cities[][50]) {
    int dist[MAX];    // Shortest distance from src
    int visited[MAX];
	int i,count,v;// Track visited nodes

    for ( i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printDistances(dist, cities, src);
}

int main() {
	int i,j;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar(); // consume newline

    char cities[n][50];
    for (i = 0; i < n; i++) {
        printf("Enter name of city %d: ", i + 1);
        fgets(cities[i], sizeof(cities[i]), stdin);
        cities[i][strcspn(cities[i], "\n")] = '\0';
    }

    int graph[MAX][MAX];
    printf("\nEnter adjacency matrix (0 if no direct road, distance otherwise):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("\nEnter source city index (0 to %d): ", n - 1);
    scanf("%d", &src);

    dijkstra(graph, src, cities);

    return 0;
}

