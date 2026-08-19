#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_NODES 20
#define INF 1e9

// Structure to store point coordinates
typedef struct {
    int x, y;
} Point;

// Global variables for Graph Representation
int num_points;
Point points[MAX_NODES];
double dist_matrix[MAX_NODES][MAX_NODES];
int degree[MAX_NODES];
int visited_nodes[MAX_NODES];

// Helper function to find or insert a point index
int get_point_index(int x, int y) {
    for (int i = 0; i < num_points; i++) {
        if (points[i].x == x && points[i].y == y) {
            return i;
        }
    }
    points[num_points].x = x;
    points[num_points].y = y;
    return num_points++;
}

// Depth First Search to check graph connectivity
void dfs(int u) {
    visited_nodes[u] = 1;
    for (int v = 0; v < num_points; v++) {
        if (dist_matrix[u][v] < INF && !visited_nodes[v]) {
            dfs(v);
        }
    }
}

int main() {
    int test_cases;
    if (scanf("%d", &test_cases) != 1) return 0;

    for (int case_num = 1; case_num <= test_cases; case_num++) {
        int num_segments;
        scanf("%d", &num_segments);

        // Reset variables for each test case
        num_points = 0;
        memset(degree, 0, sizeof(degree));
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                dist_matrix[i][j] = (i == j) ? 0 : INF;
            }
        }

        double total_initial_length = 0;

        // Read all segments
        for (int i = 0; i < num_segments; i++) {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            int u = get_point_index(x1, y1);
            int v = get_point_index(x2, y2);

            double length = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            total_initial_length += length;

            // Track geometric distance matrix
            dist_matrix[u][v] = length;
            dist_matrix[v][u] = length;
            degree[u]++;
            degree[v]++;
        }

        // 1. Verify Connectivity
        memset(visited_nodes, 0, sizeof(visited_nodes));
        int components = 0;
        for (int i = 0; i < num_points; i++) {
            if (degree[i] > 0 && !visited_nodes[i]) {
                components++;
                dfs(i);
            }
        }

        // If the geometric graph is disjoint, it cannot be drawn continuously
        if (components > 1) {
            printf("Case %d: ~x(\n", case_num);
            continue;
        }

        // 2. Identify Odd Degree Nodes
        int odd_nodes[MAX_NODES];
        int num_odd = 0;
        for (int i = 0; i < num_points; i++) {
            if (degree[i] % 2 != 0) {
                odd_nodes[num_odd++] = i;
            }
        }

        // 3. Solve matching for odd degree vertices (Chinese Postman Problem)
        double extra_cost = 0;
        if (num_odd > 2) {
            // Compute Floyd-Warshall all-pairs shortest paths on the input segments
            for (int k = 0; k < num_points; k++) {
                for (int i = 0; i < num_points; i++) {
                    for (int j = 0; j < num_points; j++) {
                        if (dist_matrix[i][k] + dist_matrix[k][j] < dist_matrix[i][j]) {
                            dist_matrix[i][j] = dist_matrix[i][k] + dist_matrix[k][j];
                        }
                    }
                }
            }

            // Simple bitmask Dynamic Programming to find minimum weight matching
            double dp[1 << MAX_NODES];
            int max_mask = 1 << num_odd;
            for (int i = 0; i < max_mask; i++) dp[i] = INF;
            dp[0] = 0;

            for (int mask = 0; mask < max_mask; mask++) {
                if (dp[mask] == INF) continue;

                // Find first unmatched node index
                int u_idx = -1;
                for (int i = 0; i < num_odd; i++) {
                    if (!(mask & (1 << i))) {
                        u_idx = i;
                        break;
                    }
                }
                if (u_idx == -1) continue;

                // Match with another free node
                for (int v_idx = u_idx + 1; v_idx < num_odd; v_idx++) {
                    if (!(mask & (1 << v_idx))) {
                        int next_mask = mask | (1 << u_idx) | (1 << v_idx);
                        double weight = dist_matrix[odd_nodes[u_idx]][odd_nodes[v_idx]];
                        if (dp[mask] + weight < dp[next_mask]) {
                            dp[next_mask] = dp[mask] + weight;
                        }
                    }
                }
            }

            // We need to keep 2 odd vertices to allow an open Eulerian Path
            // Hence, we look for the best mask that leaves exactly 2 elements unmatched
            double min_matching = INF;
            for (int mask = 0; mask < max_mask; mask++) {
                int set_bits = 0;
                for (int i = 0; i < num_odd; i++) {
                    if (mask & (1 << i)) set_bits++;
                }
                // If we matched all but 2 nodes
                if (set_bits == num_odd - 2) {
                    if (dp[mask] < min_matching) {
                        min_matching = dp[mask];
                    }
                }
            }
            extra_cost = min_matching;
        }

        // Print final configuration to 2 decimal points
        printf("Case %d: %.2f\n", case_num, total_initial_length + extra_cost);
    }

    return 0;
}

