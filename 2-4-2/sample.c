#include <stdio.h>
#define MAX_N 10000
int heap[MAX_N], sz=0;
int L, P, N;
int A[MAX_N+1],B[MAX_N+1];

void push(int x){
    int i = sz++;
    while( i > 0 ) {
        int p = (i-1)/2;
        if (heap[p] >= x) break;
        heap[i] = heap[p];
        i=p;
    }
    heap[i]=x;
}

int pop() {
    int ret = heap[0];
    int x = heap[--sz];
    int i=0;
    while(i*2+1 <sz) {
        int a = i*2 +1, b = i * 2 + 2;
        if ( b < sz && heap[b] > heap[a] ) a = b;
        if ( heap[a] <= x) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}
int empty() {
    if (sz == 0 ) return 1;
    else return 0;
}
int viewheap() {
    int i;
    for ( i=0;i<sz;i++) {
        printf("heap[%d]=%d\n",i,heap[i]);
    }
}

int getinput() {
    int i,tmp;
    scanf(" N =");
    scanf(" %d",&N);
    printf("N = %d\n",N);
    scanf(" ,");
    scanf(" L =");
    scanf(" %d",&L);
    printf("L = %d\n",L);
    scanf(" ,");
    scanf(" P =");
    scanf(" %d", &P);
    printf("P = %d\n",P);
    scanf(" A = {");
    for ( i=0;i<N;i++) {
        scanf(" %d",&A[i]);
        scanf(" ,");
    }
    scanf(" }");
    scanf(" B = {");
    for(i=0;i<N;i++ ) {
        scanf(" %d",&B[i]);
        scanf(" ,");
    }
    for ( i=0;i<N;i++) printf("A[%d]=%d, B[%d]=%d\n",i,A[i],i,B[i]);
}

int solve(){
    A[N]=L;
    B[N]=0;
    N++;
    int i,tmp,ans =0, pos =0, tank = P;
    for ( i=0;i<N;i++) {
        int d=A[i]-pos;
        while(tank - d < 0 ) {
            if ( empty()) {
                printf(" -1 \n");
                return;
            }
            tmp = pop();
            printf("add fuel %d\n",tmp);
            tank += tmp;
            ans++;
        }
        tank -= d;
        pos = A[i];
        push(B[i]);
    }
    printf("%d\n",ans);
}


int main() {
    getinput();
    solve();
}
