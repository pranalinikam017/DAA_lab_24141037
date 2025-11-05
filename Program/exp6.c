#include <stdio.h>
#define INF 9999
#define MAX 20

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], dist[MAX], visited[MAX], count, mindist, nextnode;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = graph[i][j];

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1)
    {
        mindist = INF;
        for (int i = 0; i < n; i++)
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }

        visited[nextnode] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i])
                if (mindist + cost[nextnode][i] < dist[i])
                    dist[i] = mindist + cost[nextnode][i];

        count++;
    }

    printf("\nShortest distances from vertex %d:\n", start);
    for (int i = 0; i < n; i++)
        if (i != start)
            printf("To vertex %d: %d\n", i, dist[i]);
}

int main()
{
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);
    return 0;
}