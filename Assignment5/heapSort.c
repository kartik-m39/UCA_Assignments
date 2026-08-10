#include <stdio.h>


void heapify(int arr[], int n, int i) {
    int largest = i;

    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }

}

void heapSort(int arr[], int n){

    // Building max heap
    for(int i = n/2; i >= 0; i--){
        heapify(arr, n, i);
    }

    // deleting the max element (n-1) times to get a sorted array
    for(int i = n-1; i > 0; i--){

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int random[] = {12, 5, 8, 1, 19, 3, 7};
    int ascending[] = {1, 2, 3, 4, 5, 6, 7};
    int descending[] = {7, 6, 5, 4, 3, 2, 1};

    int n = sizeof(random) / sizeof(random[0]);

    printf("Random array:\n");
    printArray(random, n);
    heapSort(random, n);
    printArray(random, n);

    printf("\nAscending array:\n");
    printArray(ascending, n);
    heapSort(ascending, n);
    printArray(ascending, n);

    printf("\nDescending array:\n");
    printArray(descending, n);
    heapSort(descending, n);
    printArray(descending, n);

    return 0;
}
