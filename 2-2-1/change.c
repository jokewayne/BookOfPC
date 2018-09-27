#include <stdio.h>

int c[6];
int a;
const int v[6]={1,5,10,50,100,500};
int getinput() {
	scanf("c1 = %d, c5 = %d, c10 = %d, c50 = %d, c100 = %d, c500 = %d, A = %d", &c[0],&c[1],&c[2],&c[3],&c[4],&c[5],&c[6],&a);
	printf("A=%d\n",a);
	int i;
	for ( i=0;i<6;i++) { printf("c[%d]=%d\n",i,c[i]); }
}

int solve() {
	int ans = 0, i;
	printf("start solve.\n");
	for ( i=5; i>=0;i--) {
		int t = (a/v[i]<c[i])?(a/v[i]):c[i] ; 
		a -= t * v[i];
		printf("coin %d : %d pecies\n",v[i],t);
		ans += t;
	} 
	printf("solve completed.\n");
	printf("total %d coins\n",ans);
}


int main()
{
	getinput();
	solve();
	printf("2-2-1 done!\n");
}

