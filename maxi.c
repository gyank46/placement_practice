

#include<stdio.h>
#include<stdlib.h>
int sum(int *a,int n)
{

	int sum1=0,i;
	for(i=0;i<n;i++)
	{
		sum1=sum1+a[i];	
	}
	return (sum1);

}

int main()
{
	int n,c,i;
	printf("enter sizeof aary");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	c=sum(a,n);
	printf("%d",c);

	
}