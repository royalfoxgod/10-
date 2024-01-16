#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 10
void 
swap(int *,int *);
void
bubble(int *,int );
void
print_arr(int *,int );
int
main()
{
	srand((unsigned)time(NULL));
	int 	i,n;
	int a[MAX] = {0};
	
	for(i=0;i<MAX;i++){
		a[i] = rand()%100; //生成0-99的随机数
	}
	n=MAX;
	print_arr(a,n);
	bubble(a,n);
	printf("after bubble sort\n");
	print_arr(a,n);
		
	
	return 0;
}
void
swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void
bubble(int a[],int n)
{
	int 	i,j;
	for(i = 0;i<n;i++){
		for(j = 0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
			}
		}
	}
}
				
void
print_arr(int a[],int n)
{
	int	 i;
	for(i=0;i<n;i++)
		printf("a[i] = %d\n",a[i]);
}
