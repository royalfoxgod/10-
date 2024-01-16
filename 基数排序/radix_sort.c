#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 100000
typedef struct queue_node{
	int 	data;
	struct queue_node* next;
}queue_node;
typedef struct queue{
	queue_node 	*head;
	queue_node 	*rear;
}queue;
void
radix_sort(int *,int );
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
	radix_sort(a,n);
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
print_arr(int a[],int n)
{
	int	 i;
	for(i=0;i<n;i++)
		printf("a[%d] = %d\n",i,a[i]);
}
void
radix_sort(int a[],int n){
	int 	max = a[0];
	int 	i,j,radix,count,index;//i,j用于循环，radix基数用于判断桶的位置，count用于数组下标
	for(i=1;i<n;i++) if(max<a[i]) max = a[i];
	int 	d = 0;//最高位的位数
	while(max){
		d++;
		max/=10;
	}
	radix = 10;			
	queue* bucket = (queue*)malloc(sizeof(queue)*10);//创建桶
	for(i = 0;i < d;i++){
		//初始化桶
		for(j = 0;j<10;j++){
			bucket[j].head= NULL;
			bucket[j].rear = NULL;
		}
		for(j = 0;j<n;j++){
			index = a[j]%radix/(radix/10);//判断元素插入哪个桶
			queue_node *node = (queue_node*)malloc(sizeof(queue_node));
			node->data = a[j];
			node->next = NULL;
			if(bucket[index].head == NULL)
				bucket[index].head = node;
			else 
				bucket[index].rear->next = node;
			bucket[index].rear= node;
		}
		count = 0;
		for(j = 0;j<10;j++){
			while(bucket[j].head!=NULL){
				a[count++] = bucket[j].head->data;
				queue_node* tmp = bucket[j].head;
				bucket[j].head = bucket[j].head->next;
				free(tmp);
			}
		}
		radix*=10;
	}
	free(bucket);
}
