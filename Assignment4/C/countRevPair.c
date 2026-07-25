#include <stdio.h>

int count = 0;

void countPairs(int nums[], int l, int m, int r) {
    int j = m + 1;
    for (int i = l; i <= m; i++) {
        while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (m + 1);
    }
}

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
    countPairs(nums, l, m, r);
    merge(nums, l, m, r);
}

int optimizedApproach(int nums[], int n) {
    count = 0;
    mergeSort(nums, 0, n - 1);
    return count;
}

int main() {
    int arr[] = {1, 3, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", optimizedApproach(arr, n));

    return 0;
}