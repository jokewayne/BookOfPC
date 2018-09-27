#include <stdio.h>
#include <string.h>
#define max(a,b) (((a) > (b)) ? (a): (b))
#define min(a,b) (((a) < (b)) ? (a): (b))

#define MAX_N 100
#define MAX_K 100000
int a[MAX_N],m[MAX_N], n, K ;
int dp[MAX_N+1][MAX_K+1];
int viewList () {
	int i;
	for (i =0 ; i< n ; i++ ) 
		printf("a[%d]=%d, m[%d]=%d\n",i,a[i],i,m[i]); 
}
int viewdp() {
    int i,j;
    for(i=0;i<n+1;i++) {
        for(j=0;j<K+1;j++) {
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
	scanf(" \n");
	scanf("a = {");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&a[i]);
		scanf(" ,");
	}
	scanf(" }");
	scanf(" \n");
	scanf("m = {");
	for (i =0 ; i< n ; i++)
	{
		scanf(" %d",&m[i]);
		scanf(" ,");
	}
	scanf(" }");
    viewList();
    scanf(" K =");
    scanf(" %d",&K);
    printf("K = %d\n",K);
viewList();
	printf("Received Done!\n");
}


int solve( ) {
	int i,j,k;
	printf("solve start.\n");
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
	for (i=0;i<n;i++) {
        for(j=0;j<=K;j++) {
            for(k=0;k<=m[i] && k* a[i] <=j;k++) {
                dp[i+1][j] |= dp[i][j-k*a[i]];
            }
        }
	}	
    if(dp[n][K]) printf("Yes\n");
    else printf("No\n");
	printf("solve done!\n");
	viewdp();
}


int main(void)
{
	getinput();
	solve();
	printf("2-3-2 done!\n");

}


