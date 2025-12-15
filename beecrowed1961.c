#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int jump_height, num_pipes, i, height_diff;
    int possible = 1; // Flag to indicate if all jumps are possible (1 = YOU WIN, 0 = GAME OVER)

    // Read the frog's jump height (P) and the number of pipes (N)
    scanf("%i %i", &jump_height, &num_pipes);

    // Declare an array to store the pipe heights
    int pipe_heights[num_pipes];

    // Read the heights of all pipes
    for (i = 0; i < num_pipes; ++i) {
        scanf("%i", &pipe_heights[i]);
    }

    // Check the jumps between adjacent pipes
    for (i = 0; i < num_pipes - 1; ++i) {
        height_diff = pipe_heights[i] - pipe_heights[i+1];

        // If the absolute difference is greater than the allowed jump height
        if (abs(height_diff) > jump_height) {
            possible = 0; // The game is over
            break;        // No need to check further
        }
    }

    // Print the final result
    if (possible) {
        printf("YOU WIN\n");
    } else {
        printf("GAME OVER\n");
    }

    return 0;
}

