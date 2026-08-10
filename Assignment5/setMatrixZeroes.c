#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setZero(int** matrix, int rows, int cols){

    bool zeroInFirstCol = false;
    for(int row = 0; row < rows; row++){
        if(matrix[row][0] == 0) zeroInFirstCol = true;
        for(int col = 1; col < cols; col++){

            // Treating the first row and first sol as markers
            if(matrix[row][col] == 0){
                matrix[row][0] = 0;
                matrix[0][col] = 0;
            }
        }
    }

    for(int row = rows - 1; row >= 0; row--){
        for(int col = cols - 1; col >= 1; col--){
            if(matrix[row][0] == 0 || matrix[0][col] == 0){
                matrix[row][col] = 0;
            }
        }

        // First col is a speacial marker so treating it differently
        if(zeroInFirstCol){
            matrix[row][0] = 0;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {

    for (int row = 0; row < rows; row++) {

        for (int col = 0; col < cols; col++) {
            printf("%d ", matrix[row][col]);
        }

        printf("\n");
    }
}

int main() {

    int rows = 3;
    int cols = 3;

    int** matrix = malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // Initialize matrix
    int values[3][3] = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = values[i][j];
        }
    }

    printf("Before:\n");
    printMatrix(matrix, rows, cols);

    setZero(matrix, rows, cols);

    printf("\nAfter:\n");
    printMatrix(matrix, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}