#include <stdio.h>

#define n 4
#define MAX 1000000

int dist[n + 1][n + 1] = {
    { 0, 0, 0, 0, 0 },
    { 0, 0, 20, 35, 40 },
    { 0, 20, 0, 5, 15 },
    { 0, 35, 15, 0, 10 },
    { 0, 40, 5, 10, 0 },
};

int memo[n + 1][1 << (n + 1)];

int min(int a, int b) {
    return a < b ? a : b;
}

int fun(int i, int mask) {
    if (mask == ((1 << i) | 3))
        return dist[1][i];

    if (memo[i][mask] != 0)
        return memo[i][mask];

    int res = MAX;

    for (int j = 1; j <= n; j++)
        if ((mask & (1 << j)) && j != i && j != 1)
            res = min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);

    return memo[i][mask] = res;
}

int main() {
    int ans = MAX;

    for (int i = 1; i <= n; i++)
        ans = min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);

    printf("The cost of most efficient tour = %d\n", ans);

    return 0;
}
