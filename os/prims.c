#include <stdio.h>
#define INF 999

int c[10][10], v[10], d[10], par[10], n;

int prim(int s) {
    int sum = 0, u, min;
    for (int i = 1; i <= n; i++) { 
    par[i] = s; d[i] = c[s][i]; v[i] = 0; }
    v[s] = 1;

    for (int i = 1; i < n; i++) {
        min = INF;
        for (int j = 1; j <= n; j++)
            if (!v[j] && d[j] < min) { min = d[j]; u = j; }
        v[u] = 1;
        sum += min;
        printf("%d -> %d  cost=%d\n", par[u], u, sum);
        for (int j = 1; j <= n; j++)
            if (!v[j] && c[u][j] < d[j]) { d[j] = c[u][j]; par[j] = u; }
    }
    return sum;
}

int main() {
    int s;
    printf("Enter n: "); scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    printf("Enter source: "); scanf("%d", &s);
    printf("\nMST cost = %d\n", prim(s));
}