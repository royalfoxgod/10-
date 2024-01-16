#include	<stdio.h>
#define 	MAX 100000
void
insert_sort(int *,int );
void
init_arr(int *,int );
void
print_arr(int *,int);

int 
main()
{
	int 	a[MAX]={0};
	int 	n = MAX;
	init_arr(a,n);
//	print_arr(a,n);
	insert_sort(a,n);
	printf("----after sort----\n");
//	print_arr(a,n);
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
insert_sort(int a[],int n)
{
	int 	i,j;
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){//找到合适的位置插入
			int tmp = a[i+1];
			for(j=i;j>=0;j--){//不要忘记等于零的情况
				if(a[j]<tmp) break;
				else a[j+1] = a[j];	
			}
			a[j+1] = tmp;//到合适的位置
		}
	}
}
			
void
print_arr(int a[],int n)
{
	int	 i;
	for(i=0;i<n;i++)
		printf("a[%d] = %d\n",i,a[i]);
}
