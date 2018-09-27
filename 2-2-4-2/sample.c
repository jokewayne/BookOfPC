#include <stdio.h>
#define MAX_N 10000
typedef long long ll;
int l[MAX_N], n  ;
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("l[%d]=%d\n",i,l[i]); 
}
int getinput(void)
{
	int i;
	scanf("N =");
	scanf(" %d",&n);
	printf("N = %d\n",n);
    scanf(" ,");
	scanf(" L =");
    scanf(" {");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&l[i]);
		scanf(" ,");
	}
	scanf("}");
	viewList();
	printf("Received Done!\n");
}


int swap( int i, int j) {
    int tmp=0;
    tmp = l[i];
    l[i]=l[j];
    l[j]=tmp;
    return 0;
}

int solve( ) {
    ll ans =0 ;
    int nn = n,i,t;
	printf("solve start.\n");
    while ( nn > 1 ) {
        int mii1 = 0, mii2 = 1;
        if ( l[mii1] > l [mii2] ) swap(mii1,mii2);
        for (i=2;i<nn;i++) {
            if (l[i]<l[mii1]) {
                mii2 = mii1;
                mii1 = i;
            } else if ( l[i] < l[mii2] ) {
                mii2=i;
            }
        }
        t = l[mii1] + l[mii2];
        ans+=t;
        if (mii1 == nn - 1 ) swap(mii1,mii2);
        l[mii1] =t;
        l[mii2]=l[nn-1];
        nn--;
    }
	printf("solve done!\n");
	printf("answer is %lld.\n", ans);
}


int main(void)
{
	getinput();
	solve();
	printf("2-2-4-2 done!\n");

}


