#include<stdio.h>
//#include<math.h>

void matrix2by2mult(int a[2][2], int b[2][2], int result[2][2]);
void matrixPadder(int n, int a[n][n], int b[n][n], int a2[n+1][n+1], int b2[n+1][n+1]);
void matrixDivider(int m, int r, int c, int a2[m][m], int b2[m][m], int result[m][m]);
void matrixMultiplication(int n, int a[n][n], int b[n][n], int result[n][n]);

int main()
{
    int n, i, j;
    printf("\nEnter size of the Odd-dimensional Square 2D-array: ");
    scanf("%d", &n);

    if (n % 2 == 1)
    {
        int a[n][n], b[n][n], result[n][n];
        printf("\nEnter %d elements into the 1st Sorted-array: ", n * n);
        for (i = n-1; i >= 0; i--)
            for (j = n-1; j >= 0; j--)
                scanf("%d", &a[i][j]);

        printf("\nEnter %d elements into the 2nd Sorted-array: ", n * n);
        for (i = n-1; i >= 0; i--)
            for (j = n-1; j >= 0; j--)
                scanf("%d", &b[i][j]);

        matrixMultiplication(n, a, b, result);

        printf("\nResultant array is:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%d, ", result[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("\nEnter correct dimensions for the matrices: ");
    }

    return 0;
}

void matrixMultiplication(int n, int a[n][n], int b[n][n], int result[n][n])
{
    int m = n + 1;
    int a2[m][m], b2[m][m];

    matrixPadder(n, a, b, a2, b2);

    matrixDivider(m, 0, 0, a2, b2, result);
}

void matrixPadder(int n, int a[n][n], int b[n][n], int a2[n+1][n+1], int b2[n+1][n+1])
{
    int i, j,m=1;
   //i=0;
   while(m<n) 
   {
	m=m*2;
   }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            a2[n - i][n - j] = a[i][j];
            b2[n - i][n - j] = b[i][j];
        }

    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            if (i == 0 || j == 0)
                a2[i][j] = b2[i][j] = 0;

    printf("\nPadded 1st array is:-\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d, ", a2[i][j]);
        printf("\n");
    }

    printf("\nPadded 2nd array is:-\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d, ", b2[i][j]);
        printf("\n");
    }
}

void matrixDivider(int m, int r, int c, int a2[m][m], int b2[m][m], int result[m][m])
{
    int d = m / 2, i = r, j = c;

    if (d == 1)
    {
        int a3[2][2], b3[2][2], temp[2][2];
        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
            {
                a3[i][j] = a2[i][j];
                b3[i][j] = b2[i][j];
            }

        matrix2by2mult(a3, b3, temp);

        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                result[r + i][c + j] = temp[i][j];
                
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            	printf("%d, ",temp[i][j]);
           printf("\n");
        }
    }
    else
    {
        int a3[d][d], b3[d][d], result1[d][d], result2[d][d], result3[d][d], result4[d][d];
        matrixDivider(d, r, c, a2, b2, result1);
        matrixDivider(d, r, c + d, a2, b2, result2);
        matrixDivider(d, r + d, c, a2, b2, result3);
        matrixDivider(d, r + d, c + d, a2, b2, result4);

        for (i = 0; i < d; i++)
            for (j = 0; j < d; j++)
            {
                result[r + i][c + j] = result1[i][j];
                result[r + i][c + j + d] = result2[i][j];
                result[r + i + d][c + j] = result3[i][j];
                result[r + i + d][c + j + d] = result4[i][j];
            }
    }
}

void matrix2by2mult(int a[2][2], int b[2][2], int result[2][2])
{
    result[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    result[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    result[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    result[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}
