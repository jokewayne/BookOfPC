#include <stdio.h>
#define N 10000
#define MAX_N 2000
int n ;
char s[MAX_N];

int getinput(void)
{
	scanf("N =");
	scanf(" %d",&n);
	scanf(" \n");
	printf("N = %d\n",n);
	scanf("S =");
	scanf(" \"%[^\"]",&s);
	printf("S = %s!\n",s);
	printf("Received Done!\n");
}


int solve( ) {
	int i,a=0,b=n-1;
	printf("solve start.\n");
    while(a<=b) {
        int left = 0;
        for (i = 0; a + i <= b ; i++ ) {
            if (s[a+i] < s[b-i] ) {
                left = 1;
                break;
            } else if (s[a+i] > s[b-i] ) {
               left = 0;
               break;
            }
        }
        if (left) putchar (s[a++]);
        else putchar(s[b--]);
    }
    putchar('\n');
	printf("solve done!\n");
}


int main(void)
{
	getinput();
	solve();
	printf("2-2-3 done!\n");

}


