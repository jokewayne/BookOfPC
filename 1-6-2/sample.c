#include <stdio.h>
#define N 10000
int a[N],b[N], n, L ;
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("a[%d]=%d, b[%d]=%d\n",i,a[i],i,b[i]); 
}
int getinput(void)
{
	int i;
	scanf("L =");
	scanf(" %d",&L);
	scanf(" \n");
	printf("L = %d\n",L);
	scanf("n =");
	scanf(" %d",&n);
	printf("N = %d!\n",n);
	scanf(" \n");
	scanf("x = {");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&a[i]);
		scanf(" ,");
	}
	scanf("}");
	viewList();
	printf("Received Done!\n");
}

int sort() {
	int i,j,max=0, tmp = 0, si =0;
	for(i=0;i<n-1;i++) {
		max=a[i];
		si=i;
		for( j=i+1;j<n;j++) {
			if (a[j] >max) {
				max=a[j];
				si=j;
			} 
		}
		if ( si != i ) {
			tmp = a[i];
			a[i] = max;
			a[si]= tmp;
		}
	}
	viewList();
}

int solve( ) {
	int i,max=0,min=0,tmpmin,tmpmax,maxi;
	printf("solve start.\n");
	for (i=0;i<n;i++) {
		if ( a[i] > (L - a[i]) ) {
			tmpmin = L - a[i];
			tmpmax = a[i];
			b[i]=1;
		} else {
			tmpmin = a[i];
			tmpmax = L - a[i];
			b[i]=0;
		}
		min = (min > tmpmin ? min : tmpmin);
		if ( tmpmax > max ) maxi=i;
		max = (max > tmpmax ? max : tmpmax);
	}	
	printf("solve done!\n");
	printf("max time is %d , min time is %d\n",max,min);
	viewList();
	printf("max index is %d.\n", maxi);
}


int main(void)
{
	getinput();
	solve();
	printf("1-6-2 done!\n");

}


