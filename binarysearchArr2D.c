#include<stdio.h>
int main()
{
	int r,c,i,j,x,mid,f=0,mn,mx;
	
	printf("\n Enter size of array : ");
	scanf("%d %d",&r,&c);
	
	int arr[r][c];
	
	printf("\n Enter %d elements into the array : ",(r*c));
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);
		
	printf("\n Enter search element : ");
		scanf("%d",&x);
	
	for(j=0;j<c;j++) 
	{
        mn=0,mx=r-1;
        while(mn<=mx) 
		{
            mid=mn+((mx-mn)/2);

            if(x==arr[mid][j]) 
			{
                f = 1;
                printf("\n Element %d found at position: row-%d col-%d",x,mid+1,j+1);    	
                break;
            } 
			else if(x<arr[mid][j]) 
                 mx=mid-1; 
			else 
                mn=mid+1;
        }
    }

	if(f==0) 
        printf("\n No such element found having value %d",x);
}