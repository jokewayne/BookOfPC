#include <stdio.h>
#define MAX_N 10000
int heap[MAX_N], sz=0;

void push(int x){
    int i = sz++;
    while( i > 0 ) {
        int p = (i-1)/2;
        if (heap[p] <= x) break;
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
        if ( b < sz && heap[b] < heap[a] ) a = b;
        if ( heap[a] >= x) break;
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}

int viewheap() {
    int i;
    for ( i=0;i<sz;i++) {
        printf("heap[%d]=%d\n",i,heap[i]);
    }
}

int getinput() {
    int i,tmp;
    for(i=0;i<MAX_N;i++ ) {
        tmp=0;
        scanf(" %d",&tmp);
        printf(" %d\n",tmp);
        if(tmp == 0) break;
        push(tmp);
    }
}

int main() {
    getinput();
    viewheap();

}
