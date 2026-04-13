#include <stdio.h>
#include <stdlib.h>

// Function to find the Longest Increasing Subsequence length using O(N log N)
int solve_lis(int* arr, int n) {
    if (n == 0) return 0;

    int* tails = (int*)malloc(sizeof(int) * n);
    int size = 0;

    for (int i = 0; i < n; i++) {
        int left = 0, right = size;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (tails[mid] < arr[i]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        tails[left] = arr[i];
        if (left == size) size++;
    }

    free(tails);
    return size;
}

int main() {
    int N, M;
    // Adapt this input loop based on the specific matrix dimensions
    // and termination criteria (e.g., N=0 M=0) provided by Beecrowd.
    while (scanf("%d %d", &N, &M) && (N != 0 || M != 0)) {
        int total_elements = N * M;
        int* matrix_flat = (int*)malloc(sizeof(int) * total_elements);

        for (int i = 0; i < total_elements; i++) {
            scanf("%d", &matrix_flat[i]);
        }

        printf("%d\n", solve_lis(matrix_flat, total_elements));
        free(matrix_flat);
    }
    return 0;
}

