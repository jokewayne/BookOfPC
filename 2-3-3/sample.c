#include <stdio.h>
#include <string.h>
#define MAX_N 1000
#define MAX_M 10000
#define max(a,b) (((a) > (b)) ? (a): (b))
#define min(a,b) (((a) < (b)) ? (a): (b))
int dp[MAX_M+1][MAX_N+1], n, m, M ;

int getinput(void)
{
	int i;
	scanf("n =");
	scanf(" %d",&n);
	printf("n = %d\n",n);
	scanf(" m =");
	scanf(" %d",&m);
	printf("m = %d\n",m);
	scanf(" M =");
	scanf(" %d",&M);
    printf("M = %d\n",M);
	printf("Received Done!\n");
}


int solve( ) {
	int i,j;
	printf("solve start.\n");
    dp[0][0]=1;
    for (i=1;i<=m;i++) {
        for ( j=0;j<=n;j++) {
            if ( j - i >=0) {
                dp[i][j]= (dp[i-1][j] + dp[i][j-i]) %M;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
	printf("solve done!\n");
	printf("%d\n", dp[m][n]);
}


int main(void)
{
	getinput();
	solve();
	printf("2-3-3 done!\n");

}


