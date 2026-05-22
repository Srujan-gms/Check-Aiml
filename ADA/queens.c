#include <stdio.h>
#include <math.h>

int n, x[10];

int place(int k) {
    for (int i = 1; i < k; i++)
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
            return 0;
    return 1;
}

void print_board(int count) {
    printf("\nSolution %d:\n", count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            printf("%s ", j == x[i] ? " Q " : " X ");
        printf("\n");
    }
}

int nqueens() {
    int k = 1, count = 0;
    x[1] = 0;
    while (k > 0) {
        x[k]++;
        while (x[k] <= n && !place(k)) x[k]++;
        if (x[k] <= n) {
            if (k == n) {
                print_board(++count);
                k--;
            } else { x[++k] = 0; }
        } else k--;
    }
    return count;
}

int main() {
    printf("Enter n: "); scanf("%d", &n);
    printf("\nTotal solutions: %d\n", nqueens());
}