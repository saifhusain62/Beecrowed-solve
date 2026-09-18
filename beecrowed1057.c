#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 16

typedef struct {
    int ax, ay, bx, by, cx, cy;
    int steps;
} State;

char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N][MAX_N];
int N;

// Movement directions: North, South, East, West
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

State queue[4000000];
int head, tail;

void enqueue(State s) {
    queue[tail++] = s;
}

State dequeue() {
    return queue[head++];
}

bool is_empty() {
    return head == tail;
}

// Check if a cell is valid to move into (within grid and not a wall)
bool is_valid_cell(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && grid[x][y] != '#');
}

int bfs(State start) {
    head = 0;
    tail = 0;
    memset(visited, 0, sizeof(visited));

    enqueue(start);
    visited[start.ax][start.ay][start.bx][start.by][start.cx][start.cy] = 1;

    while (!is_empty()) {
        State curr = dequeue();

        // Check if all three are on target cells ('X')
        if (grid[curr.ax][curr.ay] == 'X' && grid[curr.bx][curr.by] == 'X' && grid[curr.cx][curr.cy] == 'X') {
            return curr.steps;
        }

        for (int i = 0; i < 4; i++) {
            // Tentative next positions
            int nax = curr.ax + dx[i], nay = curr.ay + dy[i];
            int nbx = curr.bx + dx[i], nby = curr.by + dy[i];
            int ncx = curr.cx + dx[i], ncy = curr.cy + dy[i];

            // If a move hits a wall or grid boundary, they stay put
            if (!is_valid_cell(nax, nay)) { nax = curr.ax; nay = curr.ay; }
            if (!is_valid_cell(nbx, nby)) { nbx = curr.bx; nby = curr.by; }
            if (!is_valid_cell(ncx, ncy)) { ncx = curr.cx; ncy = curr.cy; }

            // Handle collisions between players (they cannot occupy the same spot).
            // We loop up to 3 times to resolve chain reactions (e.g., A bumps into B, B bumps into C).
            for (int k = 0; k < 3; k++) {
                if ((nax == nbx && nay == nby)) {
                    // Resolve A and B collision: revert the one that actually moved
                    if (nax != curr.ax || nay != curr.ay) { nax = curr.ax; nay = curr.ay; }
                    else { nbx = curr.bx; nby = curr.by; }
                }
                if ((nax == ncx && nay == ncy)) {
                    if (nax != curr.ax || nay != curr.ay) { nax = curr.ax; nay = curr.ay; }
                    else { ncx = curr.cx; ncy = curr.cy; }
                }
                if ((nbx == ncx && nby == ncy)) {
                    if (nbx != curr.bx || nby != curr.by) { nbx = curr.bx; nby = curr.by; }
                    else { ncx = curr.cx; ncy = curr.cy; }
                }
            }

            // If the resolved state has not been visited yet, push to queue
            if (!visited[nax][nay][nbx][nby][ncx][ncy]) {
                visited[nax][nay][nbx][nby][ncx][ncy] = 1;
                State next_state = {nax, nay, nbx, nby, ncx, ncy, curr.steps + 1};
                enqueue(next_state);
            }
        }
    }
    return -1; // Trapped
}

int main() {
    int T;
    if (scanf("%d", &T) == EOF) return 0;

    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        State start = {0, 0, 0, 0, 0, 0, 0};

        for (int i = 0; i < N; i++) {
            scanf("%s", grid[i]);
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'A') { start.ax = i; start.ay = j; }
                if (grid[i][j] == 'B') { start.bx = i; start.by = j; }
                if (grid[i][j] == 'C') { start.cx = i; start.cy = j; }
            }
        }

        int ans = bfs(start);
        printf("Case %d: ", t);
        if (ans == -1) {
            printf("trapped\n");
        } else {
            printf("%d\n", ans);
        }
    }
    return 0;
}

