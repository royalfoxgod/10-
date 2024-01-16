#include	<stdio.h>
int
sqit_approximation(int x){
	long 	approximation = x/2;
	while(approximation*approximation>x&&approximation>0){
		approximation--;
	}
	return approximation;
}

int
main()
{
	int a;
	while(scanf("%d",&a)){
		printf("%d sprt = %d\n",a,sqit_approximation(a));
}
}
