#include <stdio.h>
#define N 100
#define M 100
char field[N][M+1];
int n, m ;

int viewInput ()
{
	int i,j;
	for (i=0;i<n;i++) {
		for ( j = 0; j< m ; j++ ) {
			printf("%c",field[i][j]);
		}
		printf("\n");
	}

 

}


int getinput(void)
{
	int i=0,j=0,count=n*m,ct=0;
	char c;
	scanf("N = %d , M = %d ", &n, &m);
	printf("N = %d, M = %d !\n",n,m);
	scanf(" \n");
	do
	{
		scanf("%c",&c);
		ct++;
		printf("get char %c",c);
		if ( c == '.' || c == 'w' ) {
			field[i][j] = c;
			if ( j < (m-1)) {
				j++;
			} else {
				i++;	
				j = 0;
			}
			if ( i >= n ) break;
		} 
	} while ( c != EOF || ct < count);
	printf("\nReceived Done!\n");
}

int dfs ( int x ,int y) {
	field[x][y]='.';
	int dx,dy,nx,ny;
	for ( dx = -1; dx <= 1 ; dx++ ) {
		for ( dy = -1; dy <=1; dy++) {
			nx=x+dx;
			ny=y+dy;
			if ( 0 <= nx &&  0 <= ny && nx < n && ny < m && field[nx][ny] == 'w' )
				dfs(nx,ny);
	
		}


	}
	return;
}


int solve( ) {
	int res = 0, i,j;
	printf("solve start.\n");
	for ( i =0 ; i< n; i++ ) {
		for (j = 0; j< m; j++) {
			if ( field[i][j] == 'w' )  {
				dfs(i,j);
				res++;
			}
		}
	}

	printf("solve done!\n");
	printf("there are %d water pool.\n", res);
}


int main(void)
{
	getinput();
	viewInput();
	solve();
	printf("2-1-4 done!\n");

}


