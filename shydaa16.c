#include <stdio.h>
int multi(int x[2][2],int y[2][2],int z[2][2])
{
	int a=x[0][0];
	int b=x[0][1];
	int c=x[1][0];
	int d=x[1][1];
	int e=y[0][0];
	int f=y[0][1];
	int g=y[1][0];
	int h=y[1][1];
	int p1=(f-h)*a;
	int p2=(a+b)*h;
	int p3=(c+d)*e;
	int p4=d*(g-e);
	int p5=(a+d)*(e+h);
	int p6=(b-d)*(g+h);
	int p7=(a-c)*(e+f);
	z[0][0]=p6+p5+p4-p2;
	z[0][1]=p1+p2;
	z[1][0]=p3+p4;
	z[1][1]=p1-p3+p5-p7;	
}
int main()
{
	printf("Enter 2X2 values for 1st matrix\n");
	int i,j;
	int x[2][2];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	int y[2][2];
	printf("Enter 2X2 values for 2nd matrix\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%d",&y[i][j]);
		}
	}
	int z[2][2];
	multi(x,y,z);
	printf("\nMultiplication...\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",z[i][j]);
		}
		printf("\n");
	}
	
}
