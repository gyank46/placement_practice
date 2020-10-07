#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}
int main(){
	int i,j,k=0,count=0,n,sum=0,m=0;
	printf("The length of array:\n ");
	scanf("%d",&n);
	int arr[n],arr2[n];
	printf("please enter %d array value: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	if(arr[0]>arr[1]){
			arr2[count]= 0;
			count++;
		}
	for(i=1;i<n-1;i++){
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
			arr2[count]=i;
			count++;
		}
	}
	if(arr[n-1]>arr[n-2]){
			arr2[count]= n-1;
			count++;
		}
	//printf("count is %d\n",count);
	if(count<2)
		printf("Water wont be stored in there\n");
	else{
		for(m=0;m<count-1;m++){
			for(j=arr2[m]+1;j<arr2[m+1];j++){
				if(arr[j]!=arr[arr2[m]] && arr[j]!=arr[arr2[m+1]]){
					sum=sum+min(arr[arr2[m]],arr[arr2[m+1]])-arr[j];
				//	printf("the arr[%d] is %d &The sum is %d\n",j,arr[j],sum);
				}
			}
		}
		printf("the amount of water stored is %d\n",sum);
	}
	return 0;
}
