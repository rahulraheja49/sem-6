#include <stdio.h>

#define A 0
#define B 1
#define C 2
#define MAX_NODES 100
#define O 1000000000

int n;
int e;
int capacity[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];

int min(int x, int y) {
  return x < y ? x : y;
}

int head, tail;
int q[MAX_NODES + 2];

void enqueue(int x) {
  q[tail] = x;
  tail++;
  color[x] = B;
}

int dequeue() {
  int x = q[head];
  head++;
  color[x] = C;
  return x;
}

int bfs(int start, int target) {
  int u, v;
  for (u = 0; u < n; u++) {
    color[u] = A;
  }
  head = tail = 0;
  enqueue(start);
  pred[start] = -1;
  while (head != tail) {
    u = dequeue();
    for (v = 0; v < n; v++) {
      if (color[v] == A && capacity[u][v] - flow[u][v] > 0) {
        enqueue(v);
        pred[v] = u;
      }
    }
  }
  return color[target] == C;
}

int fordFulkerson(int source, int sink) {
  int i, j, u;
  int max_flow = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      flow[i][j] = 0;
    }
  }

  while (bfs(source, sink)) {
    int increment = O;
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      increment = min(increment, capacity[pred[u]][u] - flow[pred[u]][u]);
    }
    for (u = n - 1; pred[u] >= 0; u = pred[u]) {
      flow[pred[u]][u] += increment;
      flow[u][pred[u]] -= increment;
    }
    max_flow += increment;
  }
  return max_flow;
}

int main() {
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      capacity[i][j] = 0;
    }
  }

  int n1, n2, w;
  printf("Enter the number of edges: ");
  scanf("%d", &e);
  printf("Enter the edges in the format node1 node2 weight:\n");
  for(int i = 0; i<e; i++) {
    printf("Enter edge %d: ", i+1);
    scanf("%d %d %d", &n1, &n2, &w);
    capacity[n1][n2] = w;
  }

  int s, t;
  printf("Enter the source node: ");
  scanf("%d", &s);
  printf("Enter the sink node: ");
  scanf("%d", &t);
  printf("Max Flow: %d\n", fordFulkerson(s, t));
}

/*
6
7
0 1 8
0 4 3
1 2 9
2 5 2
3 5 5
4 2 7
4 3 4
0
5
*/