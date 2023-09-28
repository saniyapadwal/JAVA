//Name:Saniya Sandip Padwal
//rollno:42
//C Programming

#include <stdio.h>
int compare(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    int size;
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);

    int arr1[size];
    int arr2[size];

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr2[i]);
    }

    int result = compare(arr1, arr2, size);

    if (result == 0) {
        printf("1");
    } else {
        printf("");
    }

    return 0;
}
