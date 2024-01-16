#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 100000
void
print_arr(int *,int );
void
quick_sort(int *,int ,int);
int
main()
{
	srand((unsigned)time(NULL));
	int 	i,n;
	int a[MAX] = {0};
	
	for(i=0;i<MAX;i++){
		a[i] = rand()%100000; //生成0-99的随机数
	}
	n=MAX;
//	print_arr(a,n);
	quick_sort(a,0,n-1);
	printf("after sort\n");
//	print_arr(a,n);
		
	
	return 0;
}
				
void
print_arr(int a[],int n)
{
	int	 i;
	for(i=0;i<n;i++)
		printf("a[%d] = %d\n",i,a[i]);
}
void
quick_sort(int a[],int low,int high)
{
	if(low<high){//递归判断条件 
		int 	pivot = a[low];
		int 	high_tmp = high;//暂存low和high变量
		int 	low_tmp = low;
		while(low_tmp<high_tmp){
			while(low_tmp<high_tmp&&pivot<=a[high_tmp]) high_tmp--;//这里不要忘记等于号 
			a[low_tmp] = a[high_tmp];
			while(low_tmp<high_tmp&&pivot>=a[low_tmp]) low_tmp++; 
			a[high_tmp]=a[low_tmp];
		}
		a[low_tmp] = pivot;
		quick_sort(a,low_tmp+1,high);
		quick_sort(a,low,low_tmp-1);	
	}
}
