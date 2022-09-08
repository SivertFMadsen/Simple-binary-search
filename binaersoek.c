#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

int binaersoek(int* set, int len, int element) {
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high) {
        mid = (high+low)/2;

        if (set[mid] == element) {
            return 1;
        } else if (element > mid) {
            low = mid + 1;
        } else if (element < mid) {
            high = mid - 1;
        }
    }

    return 0;
}

int test_binaersoek(int* set, int len) {
    for (int i = 0; i < SIZE + 1; i++) {
        if (binaersoek(set, len, i) == 0) {
            printf("Element %d not found in set.\n", i);
        }
    }
    printf("Finished.\n");
    return 0;
}

int main() {

    int* testset = malloc(sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        testset[i] = i;
    }

    clock_t start = clock();
    test_binaersoek(testset, SIZE);
    clock_t end = clock();

    free(testset);

    printf("Time elapsed: %f.\n", (double)(end - start)/CLOCKS_PER_SEC);

    return 0;
}