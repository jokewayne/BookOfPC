#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 4096 

typedef struct {
	int x;
	int y;
	int value;	
} point;

typedef struct {
	point p[MAXSIZE];
	int top;
} stack;


stack s;
int emptystack () {
	s.top = -1;
}
int viewstack ( ) {
	int i ;
	printf("\n-------stack top-----\n");
	for(i=s.top;i >= 0 ; i--) {
		printf("%d -- x:%d,y:%d\n",i,s.p[i].x,s.p[i].y);
	}
	printf("-------stack bottom-----\n");
}
int push (point *pp ) {
	if ( s.top == (MAXSIZE - 1 ) ) {
		printf("out of stack!\n");
	} else {
		s.top++;
		s.p[s.top].x = pp->x;
		s.p[s.top].y = pp->y;
	}	
	return s.top +1;
}

int pop ( point *pp) {
	if ( s.top == -1 ) {
		printf("stack is empty!\n");
	} else { 
		pp->x=s.p[s.top].x;
		pp->y=s.p[s.top].y;
		s.p[s.top].x=0;
		s.p[s.top].y=0;
		s.top--;
	}
	return s.top+1;
}

int stacksize () {
	return s.top+1;
}


#define N 100
#define M 100
#define INF 255
char field[N][M+1];
int n, m ;
int sx,sy;
int gx,gy;
int d[N][M+1];
int dx[4] = { 1,0,-1,0}, dy[4] = { 0,1,0,-1};

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
    freopen("input.txt","r",stdin);    
	scanf("N = %d , M = %d ", &n, &m);
	printf("N = %d, M = %d !\n",n,m);
	scanf(" \n");
	do
	{
		scanf("%c",&c);
		ct++;
		printf("get char %c",c);
		if ( c == '#' || c == 's' || c == '.' || c == 'g' ) {
			field[i][j] = c;
			if ( c == 's') {
				sx=i;
				sy=j;
			}
			if ( c == 'g' ) {
				gx=i;
				gy=j;
			}
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

int bfs() {
	int i,j;
	for(i=0;i<N;i++) {
		for(j=0;j<M;j++) {
			d[i][j]=INF;
		}
	}
	point start;
	point p;	
	start.x=sx;
	start.y=sy;	
	push(&start);
	d[sx][sy]=0;
	while( stacksize()) {
		pop(&p);
		if(p.x == gx && p.y ==gy) break;
		for (i=0;i<4;i++) {
			int nx = p.x +dx[i], ny= p.y+dy[i];
			if ( 0 <= nx && nx< n && 0 <=ny && ny < m && field[nx][ny] != '#' && (d[nx][ny] == INF || d[nx][ny] > (d[p.x][p.y]+1) )) 
			{
				point t;
				t.x=nx;
				t.y=ny;
				push(&t);	
				d[nx][ny]=d[p.x][p.y]+1;
			}

		}	

	}
	return d[gx][gy];
}



int solve( ) {
	int res = 0, i,j;
	printf("solve start.\n");
	res = bfs();
	printf("-------steps map-----\n");
	for ( i =0 ; i< n; i++ ) {
		for (j = 0; j< m; j++) {
			printf("%4d",d[i][j]);
		}
		printf("\n");
	}

	printf("solve done!\n");
	printf("there are %d steps to the goal.\n", res);
}


int main(void)
{
	getinput();
	viewInput();
	solve();
	printf("2-1-5 done!\n");

}


