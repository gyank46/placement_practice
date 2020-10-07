#include<stdio.h>
#include<stdlib.h>


int main()
{
    char *a;
    a=(char*)malloc(sizeof(char)*4);
    int s=sizeof(a)/sizeof(char);
    printf("%d",s);
}