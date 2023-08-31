#include <stdio.h>
#include <stdbool.h>

#define NODE_COUNT 9
int graph[NODE_COUNT ][NODE_COUNT ] = {
    {},          // Node 0 (Not used)
    {2, 3, 4},   // Node 1
    {1, 5, 6},   // Node 2
    {1},         // Node 3
    {1, 7},      // Node 4
    {2, 8},      // Node 5
    {2, 8},      // Node 6
    {4},         // Node 7
    {5, 6}       // Node 8
};
bool visited[NODE_COUNT ];

void dfs(int node) {
    printf("%d\n", node);
    visited[node] = true;

    for (int i = 0; i < sizeof(graph[node]) / sizeof(graph[node][0]); i++) {
        int neighbor =0; 
        neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    for (int i = 0; i <= NODE_COUNT; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    dfs(1);

    return 0;
}