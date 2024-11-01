
/*Step 1: isValid Function
The isValid function checks whether a specified position is within
arr of length length. 
This function returns true if pos is valid; otherwise, false.
*/

#include <stdio.h>
#include <stdbool.h>

// Function to check if the position is valid within the array bounds
bool isValid(const int arr[], int length, int pos) {
    return pos >= 0 && pos < length; // Valid if pos is within 0 and length - 1
}

// Function to remove an element from the array at a given position
void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position.\n");
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements left
    }
    arr[length - 1] = 0; // Optional: clear last element
}

/* Step 2: remove_element Function
The remove_element function removes the element at a specified index (pos) by shifting the elements that follow it to the left. 
The last element is set to zero.
*/

// Main function to test both remove element
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int length = 5;

    printf("Array before removal: ");
    for (int i = 0; i < length; i++) printf("%d ", arr[i]);
    printf("\n");

    // Testing remove_element at position 2
    remove_element(arr, length, 2);

    printf("Array after removal at position 2: ");
    for (int i = 0; i < length; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
