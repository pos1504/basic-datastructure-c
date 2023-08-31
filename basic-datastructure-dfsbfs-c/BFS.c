#include <stdio.h>
#include <stdbool.h>

#define NODE_COUNT 9
#define QUEUE_SIZE 100

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
int queue[QUEUE_SIZE];
int front = 0;
int rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

bool isQueueEmpty() {
    return front == rear;
}

void bfs(int startNode) {
    enqueue(startNode);
    visited[startNode] = true;

    while (!isQueueEmpty()) {
        int node = dequeue();
        printf("%d\n", node);

        for (int i = 0; i < sizeof(graph[node]) / sizeof(graph[node][0]); i++) {
            int neighbor = graph[node][i];
            if (!visited[neighbor]) {
                enqueue(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    for (int i = 0; i <= NODE_COUNT; i++) {
        visited[i] = false;
    }
        visited[0] =true;
    bfs(1);

    return 0;
}