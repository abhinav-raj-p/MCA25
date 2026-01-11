#include <stdio.h>

int main() {
    int n, e;
    int graph[10][10] = {0};
    int indeg[10] = {0};
    int topo[10];
    int visited[10] = {0};
    int u, v;
    int index = 0;

    printf("Enter number of nodes (max 10): ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v) with nodes from 0 to %d:\n", n - 1);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        if (u < 0  u >= n  v < 0 || v >= n) {
            printf("Invalid edge!\n");
            return 0;
        }
        graph[u][v] = 1;
    }

    // Calculate indegree
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            indeg[j] += graph[i][j];
        }
    }

    // Kahn's Algorithm
    for (int count = 0; count < n; count++) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0 && visited[i] == 0) {
                topo[index++] = i;
                visited[i] = 1;

                for (int j = 0; j < n; j++) {
                    if (graph[i][j] == 1)
                        indeg[j]--;
                }

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Cycle detected! Topological sort not possible.\n");
            return 0;
        }
    }

    printf("Topological Order:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");

    return 0;
}