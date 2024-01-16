#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 100000
void
counting_sort(int *,int );
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
	counting_sort(a,n);
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
counting_sort(int a[],int n){
	int	i,j,min = a[0],max = a[0];
	int 	count = 0;
	for(i = 0;i<n;i++){
		if(a[i]>max) max = a[i];
		if(a[i]<min) min = a[i];
	}
	int 	length = max - min + 1;//确定临时数组长度
	int 	*tmp = (int *)malloc(sizeof(int )*length);//初始化临时数组
	for(i = 0;i<length;i++) 	tmp[i] = 0;
	for(i = 0;i<n;i++) 		tmp[a[i]-min]++;
	for(i = 0;i<length;i++){
		j = tmp[i];
		while(j>0){
			a[count++]= i+min; 
			j--;
		}
	}
	free(tmp);
}
