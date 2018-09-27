#include <stdio.h>
#define MAX_N 100000
int s[MAX_N],t[MAX_N];
int n;
typedef struct {
	int start;
	int end;
} jobtime ;
jobtime itv[MAX_N];
int viewitv() {
	int i;
	for ( i=0;i<n;i++) 
        printf("itv[%d] s:%d, e:%d\n",i,itv[i].start,itv[i].end); 
}

int getinput() {
	scanf("n = %d",&n);
	printf("n=%d\n",n);
	scanf(" ,");
	scanf(" s = {");
	int i;
	for (i=0;i<n;i++) {
		scanf(" %d",&s[i]);
		scanf(" ,");
	}
	scanf(" }");
	scanf(" ,");
	scanf(" t = {");
	for (i =0;i<n;i++) {
		scanf(" %d", &t[i]);
		scanf(" ,");
	}
	for ( i=0;i<n;i++) { printf("s[%d]=%d, t[%d]=%d\n",i,s[i],i,t[i]); }
}

int sort() {
	int i,j,minend;
	jobtime tmpjt;
	for (i=0;i<n;i++) {
		minend = i;
		for(j=i+1;j<n;j++) {
			if ( itv[minend].end > itv[j].end ) minend = j;
		}	
		if ( minend != i) {
			tmpjt.start = itv[i].start;
			tmpjt.end = itv[i].end;
			itv[i].start = itv[minend].start;
			itv[i].end = itv[minend].end;
			itv[minend].start = tmpjt.start;
			itv[minend].end = tmpjt.end;
		}
	}	
}

int solve() {
	int ans = 0, i;
	printf("start solve.\n");
	for ( i=0;i<n;i++ ) { 
		itv[i].start=s[i];
		itv[i].end=t[i];
	}
	sort();
	viewitv();
	int t=0;
	for (i=0;i<n;i++) {
		if ( t < itv[i].start ) {
			ans++;
			printf("job %d is taken.\n",i);
			t= itv[i].end;
		}
	}	
	printf("solve completed.\n");
	printf("total %d jobs has been taken.\n",ans);
}


int main()
{
	getinput();
	solve();
	printf("2-2-2 done!\n");
}

