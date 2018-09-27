#include <stdio.h>
#define MAX_N 10000
int par[MAX_N];
int rank[MAX_N];

void init(int n) {
    int i = 0;
    for(i=0;i<n;i++){
        par[i] = i;
        rank[i] = 0;
    }
}


int find (int x) {
    if ( par[x] == x ) {
        return x;
    } else {
        return par[x] = find (par[x]);
    }
}


void unite(int x, int y) {
    printf("unite %d,%d\n",x,y);
    x = find (x);
    y= find (y);
    if (x == y) return;
    if(rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if ( rank[x] == rank[y] ) rank[x]++;
    }
}

int same( int x, int y) {
    int fx,fy;
    fx = find (x);
    fy = find (y);
    if (fx == fy) printf(" %d and %d are in the same group\n",x,y);
    else printf(" %d and %d are in different group\n",x,y);
    return fx == fy;

}

int view(int x){
    printf("--------start parent---------\n");
    viewparent(x);
    printf("--------end   parent---------\n");
}

int viewparent(int x) {
    printf("par[%d]=%d\n",x,par[x]);
    if ( par[x] != x ) viewparent(par[x]);
}
int main(){
    int i=5;
    init(5);
    for ( i =0;i<5;i++) view(i);
    unite(2,4);
    unite(1,3);
    unite(0,2);
    for( i=0;i<5;i++) view(i); 
    same(2,3);
    same(1,3);
    same(0,1);
    same(0,4);

}
