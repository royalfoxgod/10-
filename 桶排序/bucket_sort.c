#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#define MAX 100000
typedef struct link_node{
	int 	data;
	struct link_node* next;
}link_node;
typedef struct 	link_list{
	link_node * head;
	int 	length;
}link_list;
void
bucket_sort(int a[],int n);
void
bubble_sort(link_list linklist);
int
sqrt_approximation(int x);
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
	bucket_sort(a,n);
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
bucket_sort(int a[],int n){
	int min = a[0],max = a[0],i,j,k;
	for(i=1;i<n;i++){
		if(min>a[i]) 	min = a[i];
		if(max<a[i])	max = a[i];
	}
	int length = max - min + 1;
	int bucket_num = sqrt_approximation(length);
	link_list *bucket = (link_list*)malloc(sizeof(link_list)*length);
	for(i = 0;i<n;i++){
		k = a[i]/length;
		link_node *node = (link_node*)malloc(sizeof(link_node));
		node->data = a[i];
		node->next = bucket[k].head;
		bucket[k].head = node;
		bucket[k].length++;	
	}
	for(i = 0;i<length;i++){
		bubble_sort(bucket[i]);
	}
	j = 0;
	link_node *tmp;
	for(i = 0;i<length;i++){
		tmp = bucket[i].head;
		while(tmp!=NULL){
			a[j++] = tmp->data;
			tmp = tmp->next;
		}
	}
}
void
bubble_sort(link_list linklist)
{
	int 	i,j,temp;
	link_node *linknode;
	for(i = 0;i<linklist.length;i++){
		linknode= linklist.head;
		for(j = 0;j<linklist.length-i-1;j++){
			if(linknode->data>linknode->next->data){
				if(linknode->next!=NULL){
					int temp = linknode->data;
					linknode->data = linknode->next->data;
					linknode->next->data = temp;
				}
			}
			linknode=linknode->next;
		}
	}
}
int
sqrt_approximation(int x){
	long 	approximation = x/2;
	while(approximation*approximation>x&&approximation>0){
		approximation--;
	}
	return approximation;
}
