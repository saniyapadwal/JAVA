//Name:Saniya Sandip Padwal
//rollno:42
//C Programming

#include <stdio.h>
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Unique elements in the array: ");
    for (int i = 0; i < size; i++) {
        int unique = 1;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                unique = 0;
                break;
            }
        }
        if (unique) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}
