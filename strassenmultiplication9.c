#include <stdio.h>

void display(int r, int c, int a[r][c]);  // Function to display a matrix
void matrixPadder(int p, int r, int c, int a[r][c], int a2[p][p]);  // Function to pad a matrix to the required size
void matrixUnPadder(int p, int r1, int c2, int result[p][p], int result2[r1][c2]);  // Function to unpad a matrix to the original size
void matrixDivider(int d, int a[d][d], int b[d][d], int result[d][d]);  // Function to divide two matrices using the Strassen algorithm
void matrix2by2mult(int a[2][2], int b[2][2], int result[2][2]);  // Function to perform a 2x2 matrix multiplication

int main() 
{
    int r1, c1, r2, c2, i, j;
    printf("\nEnter size of 2D-array for 1st matrix: ");  // Input 1st matrix dimensions
    scanf("%d %d", &r1, &c1);
    printf("\nEnter size of 2D-array for 2nd matrix: ");  // Input 2nd matrix dimensions
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) // Check if matrices are compatible for multiplication
	{
        printf("\n Dimensions of the 2 matrices are not compatible for Multiplication.");
        return 0;
    }
    int m = (r1 > c1) ? (r1 > c2 ? r1 : c2) : (c1 > c2 ? c1 : c2); // Calculating max resultant dimension
    int p = 1;
    while (p < m)
        p = p * 2; // Calculate the padding size

    int a[r1][c1], b[r2][c2], a2[p][p], b2[p][p], result[p][p], result2[r1][c2]; // Declare matrices and result

    printf("\n\n Enter %d elements into the 1st array: ", r1 * c1); 
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]); // Input values for the first matrix
            
    printf("\n\n Entered 1st array is:\n");
    display(r1, c1, a); // Display the first matrix

    printf("\n\n Enter %d elements into the 2nd array: ", r2 * c2);
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]); // Input values for the second matrix
    
    printf("\n\n Entered 2nd array is:\n");
    display(r2, c2, b); // Display the second matrix
    
    matrixPadder(p, r1, c1, a, a2);
    printf("\n\n Padded 1st array is:\n"); // Pad the matrices to the required size
    display(p, p, a2);

    matrixPadder(p, r2, c2, b, b2);
    printf("\n\n Padded 2nd array is:\n");
    display(p, p, b2);
    
    matrixDivider(p, a2, b2, result); // Perform matrix multiplication using the Strassen algorithm
    
    printf("\n\n Resultant array after Strassen Matrix Multiplication is:\n");
    matrixUnPadder(p, r1, c2, result, result2);
    display(r1, c2, result2); // Display the resultant matrix after unpadding
    return 0;
}

void display(int r, int c, int a[r][c]) // Function to display a matrix
{
    for (int i = 0; i < r; i++) 
	{
        printf("\n");
	    for (int j = 0; j < c; j++)
            printf("%d ", a[i][j]);   
    }
}

void matrixPadder(int p, int r, int c, int a[r][c], int a2[p][p]) // Function to pad a matrix to the required size
{
    int i, j; // Filling up empty padded matrix with 0
    for (i = 0; i < p; i++)
        for (j = 0; j < p; j++)
            a2[i][j] = 0;

    for (i = 0; i < r; i++) // Copy elements from the original matrix to the padded matrix
        for (j = 0; j < c; j++)
            a2[i + (p - r)][j + (p - c)] = a[i][j];
}

void matrixUnPadder(int p, int r, int c, int a[p][p], int a2[r][c]) // Function to unpad a matrix to the original size
{
    int i, j;
    for (i = 0; i < r; i++) // Copy elements from the padded matrix to the original matrix
        for (j = 0; j < c; j++)
            a2[i][j] = a[i + (p - r)][j + (p - c)];
}

void matrixDivider(int d, int a[d][d], int b[d][d], int result[d][d]) // Function to divide two matrices using the Strassen algorithm
{
	int i,j;
    if (d == 1)     // Base case: Perform simple multiplication for 1x1 matrices
        result[0][0] = a[0][0] * b[0][0];
	else     // Recursive case: Apply Strassen algorithm
	{
        int q = d / 2;  // Divide the matrices into four quadrants
        int a11[q][q], a12[q][q], a21[q][q], a22[q][q];
        int b11[q][q], b12[q][q], b21[q][q], b22[q][q];
        int r11[q][q], r12[q][q], r21[q][q], r22[q][q];
        int temp1[q][q], temp2[q][q];
        
        for (i = 0; i < q; i++) // Partition matrices into quadrants
            for (j = 0; j < q; j++) 
			{
                a11[i][j] = a[i][j];
                a12[i][j] = a[i][j + q];
                a21[i][j] = a[i + q][j];
                a22[i][j] = a[i + q][j + q];

                b11[i][j] = b[i][j];
                b12[i][j] = b[i][j + q];
                b21[i][j] = b[i + q][j];
                b22[i][j] = b[i + q][j + q];
            }

        matrix2by2mult(a11, b11, temp1); // Apply Strassen algorithm for matrix multiplication
        matrix2by2mult(a12, b21, temp2);
        for (i = 0; i < q; i++)
            for (j = 0; j < q; j++)
                r11[i][j] = temp1[i][j] + temp2[i][j];

        matrix2by2mult(a11, b12, temp1); // Apply Strassen algorithm for matrix multiplication
        matrix2by2mult(a12, b22, temp2);
        for(i = 0; i < q; i++)
            for(j = 0; j < q; j++)
                r12[i][j] = temp1[i][j] + temp2[i][j];

        matrix2by2mult(a21, b11, temp1); // Apply Strassen algorithm for matrix multiplication
        matrix2by2mult(a22, b21, temp2);
        for(i = 0; i < q; i++)
            for(j = 0; j < q; j++)
                r21[i][j] = temp1[i][j] + temp2[i][j];

        matrix2by2mult(a21, b12, temp1); // Apply Strassen algorithm for matrix multiplication
        matrix2by2mult(a22, b22, temp2);
        for(i = 0; i < q; i++)
            for(j = 0; j < q; j++)
                r22[i][j] = temp1[i][j] + temp2[i][j];

        for(i = 0; i < q; i++) // Combine the results into the final matrix
            for(j = 0; j < q; j++) 
			{
                result[i][j] = r11[i][j];
                result[i][j + q] = r12[i][j];
                result[i + q][j] = r21[i][j];
                result[i + q][j + q] = r22[i][j];
            }
    }
}

void matrix2by2mult(int x[2][2], int y[2][2], int r[2][2]) // Function to perform a 2x2 matrix multiplication
{
    int a,b,c,d,e,f,g,h,p1,p2,p3,p4,p5,p6,p7;
	a=x[0][0], b=x[0][1], c=x[1][0], d=x[1][1], e=y[0][0], f=y[0][1], g=y[1][0], h=y[1][1];
	// Perform the 2x2 matrix multiplication using Strassen's formulas
    p1 = (f - h) * a;     
    p2 = (a + b) * h;
    p3 = (c + d) * e;
    p4 = d * (g - e);
    p5 = (a + d) * (e + h);
    p6 = (b - d) * (g + h);
    p7 = (a - c) * (e + f);
	// Populate the resulting matrix
    r[0][0] = (p6 + p5 + p4 - p2); 
    r[0][1] = (p1 + p2);
    r[1][0] = (p3 + p4);
    r[1][1] = (p1 - p3 + p5 - p7);
}