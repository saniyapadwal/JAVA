//Name:Saniya Sandip Padwal
//rollno:42
//C Programming

#include <stdio.h>
void main()
{
    int arr[50][50],i = 0,j = 0, n = 0;
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; ++j)
            printf(" ");
            for (j = 0; j <= i; ++j)
             {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
