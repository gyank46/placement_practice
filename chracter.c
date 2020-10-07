#include<stdio.h>
#include<stdlib.h>
int vowelcount(char *a)
{
	int count=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='a'|| a[i]=='i'||a[i]=='e'||a[i]=='o'||a[i]=='u')
			{
				printf("%c",a[i]);
					count=count+1;
			}

	}
	return (count);

}


int main()
{
	char *a;
	int i,c;
	a=(char*)malloc(sizeof(char));
	/*int size;
	scanf("%d",&size);
	char a[size];*/
	printf("enter the charters\n");
	scanf("%s",a);
	/*int count=0;
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='a'|| a[i]=='i'||a[i]=='e'||a[i]=='o'||a[i]=='u')
			{
				printf("%c",a[i]);
				count=count+1;
			}
	}
	printf("%d",count);*/
	c=vowelcount(a);
	printf("%d\n",c);
	return 0;
}