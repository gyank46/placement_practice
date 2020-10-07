#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int* add1(int a[],int x,int n)
{
	int *b,index=0,i;
	b=(int *)malloc((n+1)*(sizeof(int)));
	for(i=0;i<n;i++)
	{
		if(a[i]>x)
		{
			index=i;
			break;
		}
	}
	if(i==n)
		index=n;
	int j=0;
	for(int i=0;i<n+1;i++)
	{
		if(i==index)
			*(b+i)=x;
		else
		{
			*(b+i)=a[j];
			j++;
		}
	}
	return b; 	
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=3*(i+1);
	}
	int x;
	scanf("%d",&x);
	int *b;
	b=add1(a,x,n);
	for(int i=0;i<n+1;i++)
		printf("%d ",*(b+i));
	printf("\n");
	return 0;
}