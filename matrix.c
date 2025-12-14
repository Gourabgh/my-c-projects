#include <stdio.h>
#include <stdlib.h>

#define MAX 10 

// Function Prototypes
void getDimensionsFromMenu(int *rows, int *cols, int matrixNumber);
void readMatrix(int matrix[MAX][MAX], int row, int col);
void printMatrix(int matrix[MAX][MAX], int row, int col);
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2);

int main() {
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    // --- STEP 1: Select Dimensions from the "Set" ---
    printf("--- MATRIX A CONFIGURATION ---\n");
    getDimensionsFromMenu(&r1, &c1, 1);

    printf("\n--- MATRIX B CONFIGURATION ---\n");
    getDimensionsFromMenu(&r2, &c2, 2);

    // --- STEP 2: The Brutal Logic Check ---
    printf("\nChecking compatibility: Matrix A (%dx%d) vs Matrix B (%dx%d)...\n", r1, c1, r2, c2);
    
    if (c1 != r2) {
        printf("CRITICAL ERROR: Dimension Mismatch.\n");
        printf("To multiply matrices, Cols of A (%d) must equal Rows of B (%d).\n", c1, r2);
        printf("You selected incompatible formats. The program will now terminate.\n");
        return 1;
    }
    printf("Status: Compatible. Resultant Matrix will be (%dx%d).\n", r1, c2);

    // --- STEP 3: Input Elements ---
    printf("\nEnter elements for Matrix A (%dx%d):\n", r1, c1);
    readMatrix(first, r1, c1);

    printf("\nEnter elements for Matrix B (%dx%d):\n", r2, c2);
    readMatrix(second, r2, c2);

    // --- STEP 4: Calculate ---
    // Clear result memory
    for(int i=0; i<r1; i++) {
        for(int j=0; j<c2; j++) {
            result[i][j] = 0;
        }
    }

    multiplyMatrices(first, second, result, r1, c1, r2, c2);

    // --- STEP 5: Output ---
    printf("\nResultant Matrix (%dx%d):\n", r1, c2);
    printMatrix(result, r1, c2);

    return 0;
}

// Helper function to show menu and set pointers
void getDimensionsFromMenu(int *rows, int *cols, int matrixNumber) {
    int choice;
    printf("Select format for Matrix %d:\n", matrixNumber);
    printf("1. 2x2\n");
    printf("2. 2x3\n");
    printf("3. 2x4\n");
    printf("4. 3x2\n");
    printf("5. 3x3\n");
    printf("6. 3x4\n");
    printf("7. 4x2\n");
    printf("8. 4x3\n");
    printf("9. 4x4\n");
    printf("10. Custom Input (Enter manually)\n");
    printf("Enter choice (1-10): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: *rows = 2; *cols = 2; break;
        case 2: *rows = 2; *cols = 3; break;
        case 3: *rows = 2; *cols = 4; break;
        case 4: *rows = 3; *cols = 2; break;
        case 5: *rows = 3; *cols = 3; break;
        case 6: *rows = 3; *cols = 4; break;
        case 7: *rows = 4; *cols = 2; break;
        case 8: *rows = 4; *cols = 3; break;
        case 9: *rows = 4; *cols = 4; break;
        case 10: 
            printf("Enter custom rows: "); scanf("%d", rows);
            printf("Enter custom cols: "); scanf("%d", cols);
            break;
        default:
            printf("Invalid choice. Defaulting to 2x2.\n");
            *rows = 2; *cols = 2;
    }
}

void readMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Aesthetic formatting: Adding brackets visually
        printf("| ");
        for (int j = 0; j < col; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("|\n");
    }
}

void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}