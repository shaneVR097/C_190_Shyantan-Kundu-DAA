#include <stdio.h>
#include <conio.h>
int main() 
{
    int n, x;
    printf("\n Enter the size of the sorted array: ");
    scanf("%d", &n);
    int arr[n];

    printf("\n Enter %d elements into the sorted array: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n Enter element whose frequency is to be printed : ");
    scanf("%d", &x);
    int f = -1, l = -1, k=0, lb = 0, ub = n - 1;
    while (lb <= ub) 
	{
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == x) 
		{
            f = mid;
            l = mid;
            while (f > lb && arr[f - 1] == x) 
                f--;
            while (l < ub && arr[l + 1] == x) 
                l++;
            k=l-f+1;
            break;
        } 
		else if (arr[mid] > x) 
            ub = mid - 1;
		else 
            lb = mid + 1;
    }

    if (f == -1) 
        printf("\n No such element found having value %d",x);
    else
        printf("\n Frequency of %d is: %d",x,k);

    getch();
}