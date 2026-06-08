#include <stdio.h>
#include <stdlib.h>

long long int merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long int inv_count = 0;

    while ((i <= mid) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long int mergeSort(int arr[], int temp[], int left, int right) {
    long long int inv_count = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int *arr = (int *)malloc(n * sizeof(int));
        int *temp = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        long long int swaps = mergeSort(arr, temp, 0, n - 1);

        if (swaps % 2 != 0) {
            printf("Marcelo\n");
        } else {
            printf("Carlos\n");
        }

        free(arr);
        free(temp);
    }
    return 0;
}

