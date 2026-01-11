#include <stdio.h>
#include <limits.h>

#define MAX 10

int adj[MAX][MAX];
int visited[MAX];

void prims(int vertices, int start)
{
    int parent[MAX], key[MAX];

    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[start] = 0;
    parent[start] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int min = INT_MAX, u = -1;

        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < vertices; v++)
        {
            if (adj[u][v] && !visited[v] && adj[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }

    printf("\nEdge\tWeight\n");
    for (int i = 0; i < vertices; i++)
    {
        if (parent[i] != -1)
        {
            printf("%d - %d\t%d\n", parent[i], i, adj[i][parent[i]]);
        }
    }
}

int main()
{
    int u, v, vertices, edges, w, start;

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &vertices);

    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &start);

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges and their weights (u v w):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    prims(vertices, start);
    return 0;
}