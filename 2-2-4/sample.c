#include <stdio.h>
#define N 10000
int x[N], n, r ;
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("x[%d]=%d\n",i,x[i]); 
}
int getinput(void)
{
	int i;
	scanf("N =");
	scanf(" %d",&n);
	scanf(" \n");
	printf("N = %d\n",n);
	scanf("R =");
	scanf(" %d",&r);
	printf("R = %d!\n",r);
	scanf(" \n");
	scanf("X = {");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&x[i]);
		scanf(" ,");
	}
	scanf("}");
	viewList();
	printf("Received Done!\n");
}

int sort() {
	int i,j,min=0, tmp = 0, si =0;
	for(i=0;i<n-1;i++) {
		min=x[i];
		si=i;
		for( j=i+1;j<n;j++) {
			if (x[j] < min) {
				min=x[j];
				si=j;
			} 
		}
		if ( si != i ) {
			tmp = x[i];
			x[i] = min;
			x[si]= tmp;
		}
	}
	viewList();
}

int solve( ) {
	int i=0,ans=0;
	printf("solve start.\n");
    while ( i < n ) {
        int s = x[i++];
        while ( i < n && x[i] <= s + r ) i++;
        int p= x[i-1];
        printf("point %d is noted\n", p);
        while ( i < n && x[i] <= p + r ) i++;
        ans++;
    }
	printf("solve done!\n");
	printf("answer is %d.\n", ans);
}


int main(void)
{
	getinput();
    sort();    
	solve();
	printf("2-2-4 done!\n");

}


