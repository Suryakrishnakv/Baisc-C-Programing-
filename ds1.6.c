#include <stdio.h> 
#define MAX 10 
void inputMatrix(int matrix[MAX][MAX], int rows, int cols); 
void displayMatrix(int matrix[MAX][MAX], int rows, int cols); 
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows, int cols); 
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows, int cols); 
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows1, int cols1, int rows2, int cols2); 
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int 
rows, int cols); 
int determinant(int matrix[MAX][MAX], int n); 
int main() { 
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX]; 
    int rows1, cols1, rows2, cols2; 
    int choice, det; 
    printf("Enter number of rows and columns for first matrix: ");  
    scanf("%d %d", &rows1, &cols1); 
    printf("Enter number of rows and columns for second matrix: "); 
    scanf("%d %d", &rows2, &cols2); 
    if (rows1 != rows2 || cols1 != cols2) 
	{ 
        printf("Matrices must have the same dimensions for addition and subtraction.\n"); 
        return 0; 
    } 
    printf("\nEnter elements for first matrix:\n"); 
    inputMatrix(matrix1, rows1, cols1); 
    printf("\nEnter elements for second matrix:\n"); 
    inputMatrix(matrix2, rows2, cols2); 
 
    do { 
        printf("\nMenu:\n"); 
        printf("1. Add Matrices\n"); 
        printf("2. Subtract Matrices\n"); 
        printf("3. Multiply Matrices\n"); 
        printf("4. Transpose Matrix\n"); 
        printf("5. Determinant of Matrix\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch(choice) { 
            case 1: 
                addMatrices(matrix1, matrix2, result, rows1, cols1); 
                printf("\nResult of addition:\n"); 
 
                displayMatrix(result, rows1, cols1); 
                break; 
            case 2: 
                subtractMatrices(matrix1, matrix2, result, rows1, cols1); 
                printf("\nResult of subtraction:\n"); 
                displayMatrix(result, rows1, cols1); 
                break; 
            case 3: 
                if (cols1 != rows2) { 
                    printf("Matrices cannot be multiplied. Columns of first matrix must equal rows of second matrix.\n"); 
                } else { 
                    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, rows2, 
cols2); 
                    printf("\nResult of multiplication:\n"); 
                    displayMatrix(result, rows1, cols2); 
                } 
                break; 
            case 4: 
                printf("\nTranspose of first matrix:\n"); 
                transposeMatrix(matrix1, result, rows1, cols1); 
                displayMatrix(result, cols1, rows1); 
                break; 
            case 5: 
                if (rows1 != cols1) { 
                    printf("Determinant can only be calculated for square matrices.\n"); 
                } else { 
                    det = determinant(matrix1, rows1); 
 
                    printf("\nDeterminant of first matrix: %d\n", det); 
                } 
                break; 
            case 6: 
                printf("Exiting...\n"); 
                break; 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } while(choice != 6); 
 
    return 0; 
} 
 
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) { 
 int i,j; 
    for (i = 0; i < rows; i++) { 
        for (j = 0; j < cols; j++) { 
            printf("Enter element at position (%d,%d): ", i + 1, j + 1); 
            scanf("%d", &matrix[i][j]); 
        } 
    } 
} 
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) { 
 int i,j; 
    for (i = 0; i < rows; i++) { 
        for (j = 0; j < cols; j++) { 
 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
} 
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows, int cols) { 
 int i,j; 
    for (i = 0; i < rows; i++) { 
        for (j = 0; j < cols; j++) { 
            result[i][j] = matrix1[i][j] + matrix2[i][j]; 
        } 
    } 
} 
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows, int cols) { 
 int i,j; 
    for (i = 0; i < rows; i++) { 
        for (j = 0; j < cols; j++) { 
            result[i][j] = matrix1[i][j] - matrix2[i][j]; 
        } 
    } 
} 
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int 
result[MAX][MAX], int rows1, int cols1, int rows2, int cols2) { 
 int i,j,k; 
    for (i = 0; i < rows1; i++) { 
        for (j = 0; j < cols2; j++) { 
 
            result[i][j] = 0; 
            for (k = 0; k < cols1; k++) { 
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            } 
        } 
    } 
} 
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int 
rows, int cols) { 
 int i,j; 
    for (i = 0; i < rows; i++) { 
        for (j = 0; j < cols; j++) { 
            result[j][i] = matrix[i][j]; 
        } 
    } 
} 
int determinant(int matrix[MAX][MAX], int n) { 
    if (n == 1) { 
        return matrix[0][0]; 
    } 
 
    int det = 0, submatrix[MAX][MAX],i,j,k; 
    for (i = 0; i < n; i++) { 
        int subi = 0; 
        for (j = 1; j < n; j++) { 
            int subj = 0; 
            for (k = 0; k < n; k++) { 
                if (k != i) { 
 
                    submatrix[subi][subj] = matrix[j][k]; 
                    subj++; 
                } 
            } 
            subi++; 
 
        } 
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(submatrix, n - 1); 
    } 
    return det; 
} 

