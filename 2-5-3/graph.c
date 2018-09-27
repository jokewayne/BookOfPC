#include <stdio.h>
#include <string.h>

#define MAX_V 1000
typedef struct edge {
    int e[MAX_V];
    int size;
}graph;

struct edge G[MAX_V];
int V;
int color[MAX_V];
int n;
int dfs(int v, int c) {
    color[v] = c;
    int i;
    for(i = 0; i < G[v].size; i++) {
        if ( color[G[v].e[i]] == c ) return 0;
        if ( color[G[v].e[i]] == 0 && !dfs(G[v].e[i], -c ) ) return 0;
    }
    return 1;
}


int solve() {
    int i;
    for( i=0;i<V;i++) {
        if ( color[i] == 0 ) {
            if (!dfs(i,1)) {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

int addEdge ( int x, int y ) {
    int i;
    for ( i=0;i< G[x].size; i++) {
        if ( y == G[x].e[i]) break;
    }
    if ( i == G[x].size) {
        G[x].e[i] = y;
        G[x].size++;
    }
    for ( i =0; i < G[y].size;i++) {
        if ( x == G[y].e[i]) break;
    }
    if ( i == G[y].size) {
        G[y].e[i] = x;
        G[y].size++;
    }
}

int viewColor() {
    int i;
    for ( i=0;i<n;i++) 
        printf("color[%d]=%d\n",i,color[i]);

}
int getinput() {
    int i,x,y;
    scanf("n =");
    scanf(" %d",&n);
    printf("n=%d\n",n);
    V = n;
    do {
        x=-1;y=-1;
        scanf(" %d %d",&x,&y);
        printf("x=%d,y=%d\n",x,y);
        if ( x != -1 && y != -1 ) addEdge(x,y);
    } while( x != -1 && y != -1);
}

int main() {
    getinput();
    solve();
    viewColor();
    printf("2-5-3 done\n");
}


