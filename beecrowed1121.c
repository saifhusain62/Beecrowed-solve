#include <stdio.h>

int main() {
    int N, M, S;
    char arena[105][105];
    char instructions[50005];

    while (scanf("%d %d %d", &N, &M, &S) && (N != 0 || M != 0 || S != 0)) {
        int posX, posY, dir; // 0: N, 1: L (E), 2: S, 3: O (W)
        int stickers = 0;

        for (int i = 0; i < N; i++) {
            scanf("%s", arena[i]);
            for (int j = 0; j < M; j++) {
                if (arena[i][j] == 'N') { posX = i; posY = j; dir = 0; }
                else if (arena[i][j] == 'L') { posX = i; posY = j; dir = 1; }
                else if (arena[i][j] == 'S') { posX = i; posY = j; dir = 2; }
                else if (arena[i][j] == 'O') { posX = i; posY = j; dir = 3; }
            }
        }

        scanf("%s", instructions);

        for (int i = 0; i < S; i++) {
            if (instructions[i] == 'D') {
                dir = (dir + 1) % 4;
            } else if (instructions[i] == 'E') {
                dir = (dir + 3) % 4;
            } else if (instructions[i] == 'F') {
                int nextX = posX, nextY = posY;
                if (dir == 0) nextX--;
                else if (dir == 1) nextY++;
                else if (dir == 2) nextX++;
                else if (dir == 3) nextY--;

                // Check boundaries and obstacles
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && arena[nextX][nextY] != '#') {
                    posX = nextX;
                    posY = nextY;
                    if (arena[posX][posY] == '*') {
                        stickers++;
                        arena[posX][posY] = '.'; // Remove sticker after collection
                    }
                }
            }
        }
        printf("%d\n", stickers);
    }
    return 0;
}

