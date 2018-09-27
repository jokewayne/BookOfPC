#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 1024

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
	viewstack();
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
	viewstack();
	return s.top+1;
}

int stacksize () {
	return s.top+1;
}
int main () {
	point a,b;
	emptystack();
	a.x=41;
	a.y=82;
	a.value=39;
	b.x=11;
	b.y=22;
	b.value=33;
	printf("x:%d,y:%d,value:%d\n",a.x,a.y,a.value);
	int i;
	int size=0;
	size=push(&b);
	push(&b);
	push(&b);
	size=push(&a);
	printf("size after push is %d\n",size);
	size=pop(&a);	
	printf("x:%d,y:%d,value:%d\n",a.x,a.y,a.value);
	printf("size after pop is %d\n",size);
}
