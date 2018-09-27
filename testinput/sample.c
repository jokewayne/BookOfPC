#include <stdio.h>
#define N 10000
int main(void)
{
	int a[N],l,n,i,x;
	scanf("L =");
	scanf(" %d",&l);
	printf("L=%d\n",l);
	scanf("\n");
	scanf("n =");
	//scanf("=");
	scanf(" %d",&n);
	printf("N = %d!\n",n);
	scanf("\n");
	scanf("a = {");
	//scanf("=");
	//scanf("{");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&a[i]);
		scanf(" ,");
	}
	scanf("}");
	for (i = 0; i< n; i++)
		printf(" a[%d] is %d!\n",i,a[i]);
	scanf("\n");
	scanf("t =");
	scanf(" %d",&x);
	printf("t = %d\n",x);
	printf("Done!\n");
}




