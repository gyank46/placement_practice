#include<stdlib.h>
#include<stdio.h>


void swap(int p,int q){
	int t;
	t=p;
	p=q;
	q=t;
}
int main()
{
	int a=25,b=36;	
	swap(a,b);
	printf("a=%d, b=%d",a,b);

	return 0;


}