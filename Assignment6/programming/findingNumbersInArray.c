#include <stdio.h>

int findNumber(int arr[], int n){
    
    int answer = 0;

    for(int bit = 0; bit < 32; bit++){

        // count the number of set bits for each number
        int count = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] & (1<<bit)){
                count++;
            }
        }

        // all the numbers are occuring 3 times co their set bit count will be multiple of 3
        // whereas the special number occurs 4 times leaving 1 bit on 4 % 3
        if(count % 3 != 0){
            answer |= (1<<bit);
        }
    }

    return answer;
}

void printArray(int arr[], int n) {
    printf("Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {
        1, 2, 3, 4,
        1, 2, 4,
        1, 2, 3,
        4, 3, 3
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    int answer = findNumber(arr, n);

    printf("Number repeating 4 times: %d\n", answer);

    return 0;
}