#include <stdio.h>

/**
 * @brief Performs an iterative binary search on a sorted integer array.
 * * @param arr The sorted array to search in.
 * @param left The starting index of the subarray.
 * @param right The ending index of the subarray.
 * @param target The element to search for.
 * @return The index of the target element if found, otherwise -1.
 */
int iterativeBinarySearch(int arr[], int left, int right, int target) {
    // Loop continues as long as the search space [left...right] is valid
    while (left <= right) {
        // Calculate mid point, preventing potential overflow for large arrays
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, ignore the left half
        if (arr[mid] < target)
            left = mid + 1;

        // If target is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If we reach here, the element was not present
    return -1;
}

/**
 * @brief Performs a recursive binary search on a sorted integer array.
 * * @param arr The sorted array to search in.
 * @param left The starting index of the subarray.
 * @param right The ending index of the subarray.
 * @param target The element to search for.
 * @return The index of the target element if found, otherwise -1.
 */
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        // Calculate mid point
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;

        // If target is greater, search the right subarray
        if (arr[mid] < target)
            return recursiveBinarySearch(arr, mid + 1, right, target);

        // If target is smaller, search the left subarray
        return recursiveBinarySearch(arr, left, mid - 1, target);
    }

    // Base case: Element is not present in the array
    return -1;
}

// --- Main function to demonstrate usage ---
int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int target1 = 23;
    int target2 = 7;

    printf("Sorted Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // --- Test Iterative Search ---
    printf("--- Iterative Search ---\n");
    int result1 = iterativeBinarySearch(arr, 0, n - 1, target1);
    if (result1 != -1) {
        printf("Element %d found at index %d.\n", target1, result1);
    } else {
        printf("Element %d not found in the array.\n", target1);
    }

    int result2 = iterativeBinarySearch(arr, 0, n - 1, target2);
    if (result2 != -1) {
        printf("Element %d found at index %d.\n", target2, result2);
    } else {
        printf("Element %d not found in the array.\n", target2);
    }

    // --- Test Recursive Search ---
    printf("\n--- Recursive Search ---\n");
    int result3 = recursiveBinarySearch(arr, 0, n - 1, target1);
    if (result3 != -1) {
        printf("Element %d found at index %d.\n", target1, result3);
    } else {
        printf("Element %d not found in the array.\n", target1);
    }

    int result4 = recursiveBinarySearch(arr, 0, n - 1, target2);
    if (result4 != -1) {
        printf("Element %d found at index %d.\n", target2, result4);
    } else {
        printf("Element %d not found in the array.\n", target2);
    }

    return 0;
}
