#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j,f=0,p;
	printf("\n Enter size of array: ");
	scanf("%d",&n);
	int a[n];
	printf("\n Enter %d elements into the array:\n ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{	
		if( (i+1)<n && a[i]<a[i+1] ) 
			if( (i+2)<n && a[i+1]>a[i+2] )
				p=(i+1),f=1,j=1;
			else
				j=0;
		
		if(j==1)
		{	
			printf("\n Bitonic sequence is found and it occurs at the element '%d' at position %d\n",a[p],p+1);
			j=0;
		}
	}
	if(f==0)
		printf("\n Bitonic sequence is not found for given sequence of numbers ")	;
	getch();
}