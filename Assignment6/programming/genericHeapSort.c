#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t elementSize) {
    void *temp = malloc(elementSize);

    memcpy(temp, a, elementSize);
    memcpy(a, b, elementSize);
    memcpy(b, temp, elementSize);

    free(temp);
}

void heapify( void *arr, int n, int i, size_t elementSize, int (*compare)(const void *, const void *)) {
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    void *base = arr;

    void *largestElement = (char *)base + largest * elementSize;

    if (left < n) {
        void *leftElement = (char *)base + left * elementSize;

        if (compare(leftElement, largestElement) > 0) {
            largest = left;
        }
    }

    largestElement = (char *)base + largest * elementSize;

    if (right < n) {
        void *rightElement = (char *)base + right * elementSize;

        if (compare(rightElement, largestElement) > 0) {
            largest = right;
        }
    }

    if (largest != i) {
        void *currentElement = (char *)base + i * elementSize;

        void *largestElement = (char *)base + largest * elementSize;

        swap(currentElement, largestElement, elementSize);

        heapify(arr, n, largest, elementSize, compare);
    }
}

void heapSort(void *arr, int n, size_t elementSize, int (*compare)(const void *, const void *)) {

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, elementSize, compare);
    }

    // Extract maximum element
    for (int i = n - 1; i > 0; i--) {

        void *first = arr;
        void *last = (char *)arr + i * elementSize;

        swap(first, last, elementSize);

        heapify(arr, i, 0, elementSize, compare);
    }
}

int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void printIntArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int random[] = {12, 5, 8, 1, 19, 3, 7};

    int n = sizeof(random) / sizeof(random[0]);

    printf("Before sorting:\n");
    printIntArray(random, n);

    heapSort(
        random,
        n,
        sizeof(int),
        compareInt
    );

    printf("After sorting:\n");
    printIntArray(random, n);

    return 0;
}
