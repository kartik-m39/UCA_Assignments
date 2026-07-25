#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void generateRandom(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = rand() % s + 1;
    }
}
void generateAscending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = i;
    }
}
void generateDescending(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        a[i] = s - i;
    }
}
void SelectionSort(int a[], int n) {
    int i, j, minIdx;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(a, i, minIdx);
        }
    }
}
void print(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        printf("%d ", a[i]);
    }
}
int main() {
    struct timeval te;
    int size = 8000;
    int step = 4000;
    int i;
    for (i = 0; i < 8; i++) {
        int a[size];
        generateRandom(a, size);
        print(a, size);
        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;
        SelectionSort(a, size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
        printf("%lld\n", end - start);

        size += step;
    }
    printf("\n");
    return 0;
}
