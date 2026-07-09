#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
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
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        } else {
            a[k++] = R[j++];
        }
    }
    while (i < n1) {
        a[k++] = L[i++];
    }
    while (j < n2) {
        a[k++] = R[j++];
    }
}
void mergeSortRec(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRec(a, left, mid);
        mergeSortRec(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}
void MergeSort(int a[], int n) {
    mergeSortRec(a, 0, n - 1);
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
        MergeSort(a, size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;
        printf("%lld\n", end - start);

        size += step;
    }
    printf("\n");
    return 0;
}
