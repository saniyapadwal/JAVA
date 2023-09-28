//Name:Saniya Sandip Padwal
//rollno:42
//C Programming

#include <stdio.h>
void rollcall(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    int rollNumbers[n];
    float percentages[n];
    for (int i = 0; i < n; i++) {
        printf("Enter Roll Number of student %d: ", i + 1);
        scanf("%d", &rollNumbers[i]);

        printf("Enter Percentage of student %d: ", i + 1);
        scanf("%f", &percentages[i]);
    }
    rollcall(rollNumbers, n);
   
    printf("\nRoll Numbers in Ascending Order are:\n");
    for (int i = 0; i < n; i++) {
        printf("\n%d-%f", rollNumbers[i],percentages[i]);
    }
}
