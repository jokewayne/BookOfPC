#include <stdio.h>
#include <string.h>
#define MAX_N 10000
#define MAX_M 10000
char s[MAX_N],t[MAX_M];
int n, m ;
int dp[MAX_N+1][MAX_M+1];
int viewdp() {
    int i,j;
    for ( i = 0 ;i<= n; i++) {
        for ( j=0;j<= m;j++) {
            printf("dp[%d][%d]=%d,",i,j,dp[i][j]);
        }
        printf("\n");
    }
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
	scanf(" s =");
	scanf(" \"%[^\"]",&s);
	printf("s = %s\n",s);
    scanf(" \"");
    scanf(" t =");
    scanf(" \"%[^\"]",&t);
    printf("t = %s\n",t);
	printf("Received Done!\n");
}


int solve( ) {
	int i,j,tmp1,tmp2;
	printf("solve start.\n");
    memset(dp,0,sizeof(dp));
    for ( i = 0 ; i< n; i++) {
        for ( j =0;j<m;j++) {
            if ( s[i] == t[j]) {
                dp[i+1][j+1]=dp[i][j]+1;
            } else {
                tmp1 = dp[i][j+1];
                tmp2 = dp[i+1][j];
                dp[i+1][j+1] = ( tmp1 > tmp2 ? tmp1:tmp2 );
            }

        }
    }
	printf("solve done!\n");
    printf("%d\n",dp[n][m]);
}


int main(void)
{
	getinput();
	solve();
    viewdp();
	printf("2-3-1-2 done!\n");

}


