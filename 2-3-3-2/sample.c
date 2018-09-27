#include <stdio.h>
#include <string.h>
#define MAX_N 1000
#define MAX_M 10000
#define max(a,b) (((a) > (b)) ? (a): (b))
#define min(a,b) (((a) < (b)) ? (a): (b))
int a[MAX_N], dp[MAX_N+1][MAX_M+1], n, m, M ;

int viewList() {
    int i;
    for(i=0;i<n;i++) printf("a[%d]=%d\n",i,a[i]);
}
int getinput(void)
{
	int i;
	scanf("n =");
	scanf(" %d",&n);
	printf("n = %d\n",n);
	scanf(" m =");
	scanf(" %d",&m);
	printf("m = %d\n",m);
    scanf(" a = {");
    for (i =0 ; i< n;i++) {
        scanf(" %d",&a[i]);
        scanf(" ,");
    }
    scanf(" }");
	scanf(" M =");
	scanf(" %d",&M);
    printf("M = %d\n",M);
    viewList();
	printf("Received Done!\n");
}


int solve( ) {
	int i,j;
	printf("solve start.\n");
    for(i=0;i<=n;i++) dp[i][0]=1;
    for (i=0;i<=n;i++) {
        for ( j=1;j<=m;j++) {
            if ( j - 1 -a[i] >=0) {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1 - a[i]] + M) % M;
            } else {
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] ) % M;
            }
        }
    }
	printf("solve done!\n");
	printf("%d\n", dp[n][m]);
}


int main(void)
{
	getinput();
	solve();
	printf("2-3-3 done!\n");

}


