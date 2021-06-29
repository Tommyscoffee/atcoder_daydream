#include <stdio.h>
//compare()はqsortで並べ替えするために使う関数。
int	compare (const void *a,const void *b){
	return *(int*)b - *(int*)a;
}
int	main()
{
	int	n,i,r=0,i = 0;
	int	arr[999];
	scanf("%d",&n);
	for (i = 0; i < n;i++)scanf("%d",&arr[i]);
	qsort(arr,n,4,compare);
	for (i = 0; i < n;i++)printf("%d",arr[i]);
	return(0);
	
}