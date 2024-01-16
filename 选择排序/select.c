#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 10
void
swap(int *,int *);
void
select_sort(int *,int );
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
	print_arr(a,n);
	select_sort(a,n);
	printf("----after select sort----\n");
	print_arr(a,n);
}
void
init_arr(int a[],int n)
{
	srand((unsigned)time(NULL));
	int 	i;
	for(i=0;i<n;i++)
		a[i] = rand()%100;

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
void
select_sort(int a[],int n)
{
	int 	i,j;
	for(i=0;i<n-1;i++){//由于前n-1个元素都是排好序的最小值，所以最后一个元素一定是最大
		int min_position = i;	//把当前位置当做最小值下标
		for(j = i+1;j<n;j++){
			 if(a[min_position]>a[j])
				min_position = j;
		}
		swap(&a[i],&a[min_position]);
	}
}
