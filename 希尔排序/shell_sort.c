#include	<stdio.h>
#define 	MAX	100000
void
print_arr(int *,int);
void
init_arr(int *,int );
void
insert_sort_gap(int *,int ,int);
void
shell_sort(int *,int);
int
main()
{
	int 	a[MAX]={0};
	int 	n = MAX;
	init_arr(a,n);
	//print_arr(a,n);
	shell_sort(a,n);
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
shell_sort(int a[],int n)
{
	int 	gap=n/2;
	while(gap){
		insert_sort_gap(a,n,gap);
		gap=gap/2;	
	}
}
void
insert_sort_gap(int a[],int n,int gap)
{
	int 	i,j;
	for(i=0;i<n-gap;i++){
		if(a[i]>a[i+gap]){//找到合适的位置插入
			int tmp = a[i+gap];
			for(j=i;j>=0;j-=gap){//不要忘记等于零的情况
				if(a[j]<tmp) break;
				else a[j+gap] = a[j];	
			}
			a[j+gap] = tmp;//到合适的位置
		}
	}
}
