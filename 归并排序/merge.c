#include	<stdio.h>
#include	<stdlib.h>

void
merge(int a[],int low,int mid,int high);
int 
main()
{
	int a[10] = {1,3,5,7,9,0,2,4,6,8};
	int 	i;
	for(i = 0;i<10;i++) printf("a[%d] = %d\n",i,a[i]);
	merge(a,0,4,9);
	printf("after sort--------------------\n");
	for(i = 0;i<10;i++) printf("a[%d] = %d\n",i,a[i]);
	return 0;
}
void
merge(int a[],int low,int mid,int high){
	int 	*tmp = (int *)malloc(sizeof(int)*(high-low+1));
	int 	i = low;
	int 	j = mid+1;
	int 	k = 0;
	while(i<=mid&&j<=high){
		if(a[i]<=a[j])	tmp[k++] = a[i++];
		else		tmp[k++] = a[j++];
	}
	while(i<=mid) 		tmp[k++] = a[i++];
	while(j<=high)		tmp[k++] = a[j++];
	for(k=0,i=low;k<=high-low;k++){
		a[i++] = tmp[k];
	}
	free(tmp);
}
