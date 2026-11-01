#include <stdio.h>
#include <string.h>

#define MAX 25

int adj[MAX][MAX];
int visited[MAX];
int path_found;

void dfs(int u, int depth) {
    visited[u] = 1;
    for (int v = 0; v < MAX; v++) {
        if (adj[u][v]) {
            for (int i = 0; i < depth; i++) printf(" ");
            if (!visited[v]) {
                path_found = 1;
                printf("%d-%d pathR(G,%d)\n", u, v, v);
                dfs(v, depth + 2);
            } else {
                printf("%d-%d\n", u, v);
            }
        }
    }
}

void solve(int case_num, int V) {
    memset(visited, 0, sizeof(visited));
    printf("Caso %d:\n", case_num);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            path_found = 0;
            dfs(i, 2);
            if (path_found) {
                printf("\n");
            }
        }
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    for (int c = 1; c <= N; c++) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][v] = 1;
        }
        
        solve(c, V);
    }
    
    return 0;
}
