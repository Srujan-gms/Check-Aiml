#include <stdio.h>
#define INF 999
#define MAX 100

int p[MAX], c[MAX][MAX], t[MAX][3];

int find(int v) {
    while (p[v]) v = p[v];
    return v;
}

void kruskal(int n) {
    int u, v, r1, r2, min, sum = 0;
    for (int k = 1; k < n; k++) {
        min = INF;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j && c[i][j] < min) {
                    u = find(i); v = find(j);
                    if (u != v) { r1 = i; r2 = j; min = c[i][j]; }
                }
        p[find(r2)] = find(r1);   // union by roots
        t[k][1] = r1; t[k][2] = r2;
        sum += min;
    }
    printf("MST cost: %d\nEdges:\n", sum);
    for (int i = 1; i < n; i++) printf("%d -> %d\n", t[i][1], t[i][2]);
}

int main() {
    int n;
    printf("Enter n: "); scanf("%d", &n);
    for (int i = 1; i <= n; i++) p[i] = 0;
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    kruskal(n);
}