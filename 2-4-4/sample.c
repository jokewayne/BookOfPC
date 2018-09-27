#include <stdio.h>
#include <string.h>
#define MAX_N 50000
#define MAX_K 100000
int N, K;
int T[MAX_K],X[MAX_K],Y[MAX_K];
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

int getinput(){
    scanf(" N =");
    scanf(" %d",&N);
    printf("N = %d\n",N);
    scanf(" ,");
    scanf(" K =");
    scanf(" %d",&K);
    printf("K = %d\n",K);
    int i;
    for(i=0;i<K;i++) {
        scanf(" t =");
        scanf(" %d",&T[i]);
        scanf(" ,");
        scanf(" x =");
        scanf(" %d",&X[i]);
        scanf(" ,");
        scanf(" y =");
        scanf(" %d",&Y[i]);
    }
    for (i =0; i< K; i++) printf("%4d: t = %d, x = %d, y = %d\n",i,T[i],X[i],Y[i]);
}

int putIn(int *s, int x) {
    int i=0;
    if( x == 0 ) return;
    while(s[i] != 0 ){
        if ( s[i] == x ) break;
        i++;
    }
    if ( s[i] == 0 ) s[i] = x; 
}

int viewGroup()
{
    int i,s[MAX_N];
    memset(s,0,sizeof(s));
    for(i=0;i<K;i++){ 
       putIn(s,X[i]);
       putIn(s,Y[i]);
    }
    i=0;
    printf("--------get info for -------\n");
    while(s[i] != 0 ) {
        view(s[i]);
        i++;
    }
    printf("--------info end------------\n");
}
int solve(){
    init(N*3);
    int ans = 0;
    int i;
    for( i = 0; i < K; i++) {
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1;
        if ( x < 0 || N <=x || y < 0 || N <= y ) {
            printf("%d is wrong, t = %d, x = %d, y = %d\n",i,T[i],X[i],Y[i]);
            ans++;
            continue;
        }
        if ( t == 1 ) {
            if (same(x,y+N) || same(x,y+2*N)) {
                view(x);
                view(y);
                printf("%d is wrong, t = %d, x = %d, y = %d\n",i,T[i],X[i],Y[i]);
                ans++;
            } else {
                unite(x,y);
                unite(x+N,y+N);
                unite(x+N*2,y+N*2);
            }
        } else {
            if (same(x,y) || same(x,y+2*N)) {
                printf("%d is wrong, t = %d, x = %d, y = %d\n",i,T[i],X[i],Y[i]);
                ans++;
            } else {
                unite(x,y+N);
                unite(x+N,y+2*N);
                unite(x+2*N,y);
            }
        }
    }
    printf("answer is %d\n",ans);
    viewGroup();
}


int main() {
    getinput();
    solve();
    printf("2-4-4 done\n");

}

int unite_main(){
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
