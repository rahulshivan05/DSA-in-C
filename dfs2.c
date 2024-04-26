#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Graph representation using an adjacency matrix
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

// Function to perform Depth-First Search
void dfs(int node, int numNodes)
{
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < numNodes; i++)
    {
        if (graph[node][i] && !visited[i])
        {
            dfs(i, numNodes);
        }
    }
}

int main()
{
    int numNodes, numEdges;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Initialize graph and visited array
    for (int i = 0; i < numNodes; i++)
    {
        for (int j = 0; j < numNodes; j++)
        {
            graph[i][j] = 0;
        }
        visited[i] = false;
    }

    // Read edges
    printf("Enter the edges:\n");
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Uncomment for undirected graph
    }

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("Depth-First Traversal: ");
    dfs(startNode, numNodes);

    return 0;
}
