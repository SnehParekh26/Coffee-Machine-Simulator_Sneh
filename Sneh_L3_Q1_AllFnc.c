#include <stdio.h>
#include <stdbool.h>

// Function to check if a position is valid in the array
bool isValid(const int arr[], int length, int pos) {
    if (pos >= 0 && pos < length) {
        return true;
    } else {
        return false;
    }
}

// Function to remove an element at a specific position
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Position is out of bounds.\n");
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0; // Set the last spot to 0 since it's now empty
}

// Function to insert an element at a specific position
void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Position is out of bounds.\n");
        return;
    }
    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
}

// Function to reshape a 1D array into a 2D array
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Error: Array length doesn't match 2D array dimensions.\n");
        return;
    }
    int k = 0;
    for (int col = 0; col < nCols; col++) {
        for (int row = 0; row < nRows; row++) {
            arr2d[row][col] = arr[k];
            k++;
        }
    }
}

// Function to make the transpose of a matrix
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}

// Function to check if there are duplicates in the array
bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = 5;
    int arr2d[2][3];
    int transposed[3][2];

    // Test the isValid function
    printf("Checking if positions are valid:\n");
    printf("Is position 3 valid? %s\n", isValid(arr, length, 3) ? "Yes" : "No");
    printf("Is position 5 valid? %s\n\n", isValid(arr, length, 5) ? "Yes" : "No");

    // Test the remove_element function
    printf("Removing element at position 2:\n");
    printf("Before: ");
    for (int i = 0; i < length; i++) printf("%d ", arr[i]);
    printf("\n");
    remove_element(arr, length, 2);
    printf("After: ");
    for (int i = 0; i < length; i++) printf("%d ", arr[i]);
    printf("\n\n");

    // Test the insert_element function
    printf("Inserting 80 at position 2:\n");
    insert_element(arr, length, 2, 80);
    printf("After: ");
    for (int i = 0; i < length; i++) printf("%d ", arr[i]);
    printf("\n\n");

    // Test the reshape function
    int flatArr[] = {10, 20, 30, 40, 50, 60};
    int flatLength = 6;
    printf("Reshaping 1D array into 2D array:\n");
    reshape(flatArr, flatLength, 2, 3, arr2d);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Test the trans_matrix function
    printf("Transpose of the 2D array:\n");
    trans_matrix(2, 3, arr2d, transposed);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", transposed[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Test the found_duplicate function
    printf("Checking for duplicates:\n");
    printf("Does the array have duplicates? %s\n", found_duplicate(arr, length) ? "Yes" : "No");

    return 0;
}
