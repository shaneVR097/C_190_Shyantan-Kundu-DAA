#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j,s,x,mx,mn,f=0;
	printf("\n Enter size of the sorted-array : ");
	scanf("%d",&n);
	int arr[n];
	printf("\n Enter %d elements into the sorted-array : \n ",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n Enter sum of 2 elements : ");
		scanf("%d",&x);
	mn=arr[0];
	mx=arr[n-1];
	i=0,j=n-1;
	while(i<j)
	{
		s=mx+mn;
		if(s==x)
		{
			printf("\n Numbers are: %d+%d=%d ",mx,mn,s);
			i++;
			mn=arr[i];
			j--;
			mx=arr[j];
			f=1;
		}
		else if(s<x)
		{
			i++;
			mn=arr[i];
		}
		else
		{
			j--;
			mx=arr[j];
		}
	}
	if(f==0) 
	{
        printf("\n No such pair found having the sum %d",x);
    }
    getch();
}
