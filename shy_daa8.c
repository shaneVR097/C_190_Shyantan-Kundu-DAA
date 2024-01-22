#include<stdio.h>
//#include<conio.h>
int main()
{
	int n,i,j,x,mid,f=0,p,k=0;
	printf("\n Enter size of the Sorted-array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\n Enter %d elements into the Sorted-array : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n Enter element whose frequency is to be printed : ");
		scanf("%d",&x);
	mid=((n-1)/2);
	for(i=0;i<n;i++)
	{
		printf("%d",arr[mid]);
		if(x==arr[mid])
		{
			p=mid;
			f=1;
			k++;
		}
		else if(x<arr[mid])
		{
			mid=mid/2;
		}
		else
		{
			mid=(n-1+mid)/2;
		}
//		printf(" Frequency of %d is: %d",x);
	}
	if(f==0) 
	{
	        printf("\n No such element found having value %d",x);
        }
	else
	{
		printf("\n Frequency of %d is: %d",x,k);
	}	
// 	getch();
}
