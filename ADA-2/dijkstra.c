#include <stdio.h>
#define INF 999

int c[10][10], d[10], v[10], n;

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) { d[i] = c[s][i]; v[i] = 0; }
    v[s] = 1;

    for (int i = 1; i <= n; i++) {
        int min = INF, u;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[j] < min) { min = d[j]; u = j; }
        v[u] = 1;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[u] + c[u][j] < d[j])
                d[j] = d[u] + c[u][j];
    }
}

int main() {
    int s;
    printf("Enter n: "); scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter source: "); scanf("%d", &s);
    dijkstra(s);
    for (int i = 1; i <= n; i++)
        printf("%d -> %d : %d\n", s, i, d[i]);
}