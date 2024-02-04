#include<stdio.h>
#include<conio.h>
void merge(int a[], int lb, int mid, int ub, int *c) 
{
    int i = lb,j = mid + 1,k = lb,b[ub + 1];
    while (i <= mid && j <= ub) 
	{
        if (a[i] <= a[j]) 
		{
            b[k] = a[i];
            i++;
        } 
		else 
		{
            *c += (mid - i + 1);
            b[k] = a[j];
            j++;
        }
        k++;
    }
	while(i<=mid) 
	{
        b[k] = a[i];
        i++;
        k++;
    }
	while (j <= ub) 
	{
        b[k] = a[j];
        j++;
        k++;
    }
	for (i = lb; i <= ub; i++)
        a[i] = b[i];
}

void MergeSort(int a[], int lb, int ub, int *c) 
{
    if (lb < ub) 
	{
        int mid=(lb+ub)/2;
        MergeSort(a, lb, mid, c);
        MergeSort(a, mid + 1, ub, c);
        merge(a, lb, mid, ub, c);
    }
}

int main() 
{
    int n, i;
    printf("\n Enter number of elements in array: ");
    scanf("%d", &n);
    int a[n];
    printf("\n Enter %d elements into the array:\n ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int lb = 0,ub = n - 1,c = 0;
    MergeSort(a, lb, ub, &c);
    printf("\n Inversion count: %d\n", c);
    return 0;
}