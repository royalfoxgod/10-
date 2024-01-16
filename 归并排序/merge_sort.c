#include	<stdio.h>
#include	<stdlib.h>
#define 	MAX 100000
void
print_arr(int *,int );

void
merge(int a[],int low,int mid,int high);
void
merge_sort(int a[],int low,int high);
void
init_arr(int *,int );

int
main()
{
	int 	a[MAX]={0};
	int 	n = MAX;
	init_arr(a,n);
//	print_arr(a,n);
	merge_sort(a,0,n-1);
	printf("----after sort----\n");
//	print_arr(a,n);
	return 0;

}

void//治
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
void//分
merge_sort(int a[],int low,int high){
	if(low<high){
		int 	mid = (low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void
init_arr(int a[],int n)
{
	srand((unsigned)time(NULL));
	int 	i;
	for(i=0;i<n;i++)
		a[i] = rand()%100000;

}
void
print_arr(int a[],int n)
{
	int	 i;
	for(i=0;i<n;i++)
		printf("a[%d] = %d\n",i,a[i]);
}
