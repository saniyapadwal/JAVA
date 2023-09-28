//Name:Saniya Sandip Padwal
//rollno:42
//C Programming

#include <stdio.h>
void main() {
    int n; 
    printf("Printing largest number in the array");
    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n]; 
    printf("Enter the elements in an array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  int largest = arr[0];

     for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("The largest number in the array is: %d\n", largest);

}
