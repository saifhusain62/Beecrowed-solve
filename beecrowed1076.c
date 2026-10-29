#include <stdio.h>

void solve() {
    int start_node;
    scanf("%d", &start_node);
    
    int V, E;
    scanf("%d %d", &V, &E);
    
    int visited_edges[50][50] = {0};
    int total_moves = 0;
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Count each unique undirected edge only once
        if (!visited_edges[u][v] && !visited_edges[v][u]) {
            visited_edges[u][v] = 1;
            visited_edges[v][u] = 1;
            total_moves += 2;
        }
    }
    
    printf("%d\n", total_moves);
}

int main() {
    int T;
    if (scanf("%d", &T) != EOF) {
        while (T--) {
            solve();
        }
    }
    return 0;
}
