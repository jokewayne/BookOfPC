#include <stdio.h>
#include <string.h>
#define MAX_N 10000
#define MAX_W 10000
int w[MAX_N],v[MAX_N], n, W ;
int dp[MAX_N + 1][MAX_W+1];
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("w[%d]=%d, v[%d]=%d\n",i,w[i],i,v[i]); 
}
int viewdp(){
    int i,j;
    for ( i=0;i<n;i++){
        for(j=0;j<W;j++) {
            printf("dp[%d][%d]=%d,",i,j,dp[i][j]);
        }
        printf("\n");
    }
}
int getinput(void)
{
	int i;
	scanf("N =");
	scanf(" %d",&n);
	printf("N = %d\n",n);
	scanf(" (w, v) = {");
	for (i =0 ; i< n ; i++)
	{
        scanf(" (");
		scanf(" %d",&w[i]);
		scanf(" ,");
        scanf(" %d",&v[i]);
        scanf(" )");
        scanf(" ,");
	}
	viewList();
	scanf(" }");
    scanf(" W =");
    scanf(" %d", &W);
    printf("W=%d\n",W);
	printf("Received Done!\n");
}

int rec(int i ,int j) {
    int res,tmp1,tmp2;
    if(dp[i][j] >= 0 ) return dp[i][j];
    if (i == n) {
        res = 0;
    } else if ( j < w[i]) {
        res = rec(i+1,j);
    } else {
        tmp1 = rec(i+1,j);
        tmp2 = rec(i+1,j-w[i]) +v[i];
        res = tmp1 > tmp2 ? tmp1:tmp2 ;
    }
    return dp[i][j]=res;
}

int solve( ) {
	printf("solve start.\n");
    memset(dp,-1,sizeof(dp));
    printf("%d\n",rec(0,W));
	printf("solve done!\n");
    viewdp();
}


int main(void)
{
	getinput();
	solve();
	printf("2-3-1 done!\n");

}


