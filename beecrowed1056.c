#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXN 105

int A[MAXN];
int B[MAXN];
int matchB[MAXN];
bool visited[MAXN];
int adj[MAXN][MAXN];
int deg[MAXN];
int N, M;

// Check if B[j] is a multiple of A[i]
bool is_multiple(int a, int b) {
    if (a == 0) {
        return b == 0;
    }
    return (b % a == 0);
}

// DFS to find an augmenting path
bool dfs(int u) {
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            visited[v] = true;
            // If v is not matched or we can find an alternate match for its current partner
            if (matchB[v] < 0 || dfs(matchB[v])) {
                matchB[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int case_num = 1; case_num <= T; case_num++) {
        // Read array A
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            deg[i] = 0; // Reset adjacency list degrees
        }

        // Read array B
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &B[j]);
        }

        // Build the bipartite graph
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (is_multiple(A[i], B[j])) {
                    adj[i][deg[i]++] = j;
                }
            }
        }

        // Initialize matching values
        memset(matchB, -1, sizeof(matchB));

        int max_matching = 0;
        for (int i = 0; i < N; i++) {
            memset(visited, false, sizeof(visited));
            if (dfs(i)) {
                max_matching++;
            }
        }

        // Output final result for the current test case
        printf("Case %d: %d\n", case_num, max_matching);
    }

    return 0;
}

