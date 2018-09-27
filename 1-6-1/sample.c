#include <stdio.h>
#define N 10000
int a[N],n;
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("a[%d]=%d\n",i,a[i]); 


}
int getinput(void)
{
	int i;
	scanf("n =");
	scanf(" %d",&n);
	printf("N = %d!\n",n);
	scanf(" \n");
	scanf("a = {");
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
	sort();
	int i,j,k,length=0,max=0, l1=0,l2=0,l3=0;
	printf("start solve.\n");
	for(i=0;i<n-2;i++) {
		for(j=i+1;j<n-1;j++) {
			for(k=j+1;k<n;k++) {
				if( a[i] < a[j] + a[k]) {
					length = a[i] + a[j] + a[k];
					if ( max < length)  {
						max = length; 
						l1 = a[i];
						l2 = a[j];
						l3 = a[k];
					}
				}
			}
		}
	}		
	printf("solve done!\n");
	printf("max length is %d , l1=%d, l2=%d, l3=%d\n",max,l1,l2,l3);
}


int main(void)
{
	getinput();
	solve();
	printf("1-6-1 done!\n");

}


