#include <stdio.h>

int count = 0;

void merge(int nums[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) L[i] = nums[l + i];
    for (int j = 0; j < n2; j++) R[j] = nums[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
            count += n1 - i;
        }
    }

    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];
}

void mergeSort(int nums[], int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;

    mergeSort(nums, l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);
}

int optimizedApproach(int nums[], int n) {
    count = 0;
    mergeSort(nums, 0, n - 1);
    return count;
}

int main() {
    int arr[] = {1, 2, 4, 1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", optimizedApproach(arr, n));

    return 0;
}