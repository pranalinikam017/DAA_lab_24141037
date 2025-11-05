#include <stdio.h>
#define INF 99999
#define MAX 10

int main() {
    int n, i, j, src, min, u;
    int cost[MAX][MAX], dist[MAX], visited[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;

    for (i = 1; i < n - 1; i++) {
        min = INF;
        for (j = 0; j < n; j++) {
            if (dist[j] < min && !visited[j]) {
                min = dist[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[u] + cost[u][j] < dist[j])
                dist[j] = dist[u] + cost[u][j];
        }
    }

    printf("\nShortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("To %d: INF\n", i);
        else
            printf("To %d: %d\n", i, dist[i]);
    }

    return 0;
}