#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 100000
void
max_heap(int a[],int low,int high);
void
heap_sort(int a[],int n);
void
swap(int *,int *);
void
init_arr(int *,int );
void
print_arr(int *,int );
int
main()
{
	int 	a[MAX]={0};
	int 	n = MAX;
	init_arr(a,n);
	//print_arr(a,n);
	heap_sort(a,n);
	printf("----after sort----\n");
	//print_arr(a,n);
	return 0;
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
void
swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void//将较小值向下坠
max_heap(int a[],int low,int high){
	int 	dad = low;
	int 	son = dad*2+1;
	while(son <= high){
		if(son+1<=high&&a[son] <a[son+1]) son++;
		if(a[son]>a[dad]){
			swap(&a[dad],&a[son]);
			dad = son;
			son = dad*2+1;
		}else 
			break;
	}
}
void
heap_sort(int a[],int n){
	int 	i;
	for(i = n/2-1;i>=0;i--)//初始化大顶堆
		max_heap(a,i,n-1);
	for(i=n-1;i>0;i--){//首尾交换继续堆排序
		swap(&a[0],&a[i]);
		max_heap(a,0,i-1);
	}
}
