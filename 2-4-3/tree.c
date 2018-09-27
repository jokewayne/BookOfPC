#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node *lch;
    struct node *rch;
}searchTree;

searchTree *g_p = NULL; 
searchTree *insert (searchTree *p, int x) {
    //treeView(p);
    if ( p == NULL ) {
        printf("inside insert NULL\n");
        searchTree *q= malloc(sizeof(searchTree));
        q->val = x;
        q->lch = NULL;
        q->rch = NULL;
        return q;
    } else {
        printf("inside insert else\n");
        if ( x < p->val ) {
            printf("inside insert smaller\n");
            p->lch = insert( p->lch, x );
        }
        else { 
            printf("inside insert bigger or equal\n");
            p->rch = insert( p->rch, x);
        }
        return p;
    }
}

int find ( searchTree *p, int x) {
    if ( p == NULL) return 0;
    else if ( x == p->val) return 1;
    else if ( x < p->val) return find (p->lch, x);
    else return find (p->rch,x);
}


searchTree *delete( searchTree *p, int x) {
    if (p == NULL) return NULL;
    else if ( x < p->val) p->lch = delete(p->lch,x);
    else if ( x > p->val) p->rch = delete(p->rch,x);
    else if ( p->lch == NULL) {
        searchTree * q = p->rch;
        free(p);
        return q;
    } else if (p->lch->rch == NULL) {
        searchTree *q = p->lch;
        q->rch = p->rch;
        free(p);
        return q;
    } else {
        searchTree *q;
        for (q = p->lch;q->rch->rch != NULL; q = q->rch);
        searchTree *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        r->rch = p->rch;
        free(p);
        return r;
    }
    return p;
}
int treeView(searchTree *p) {
    printf("--------tree start---------------\n");
    viewTree(p);
    printf("--------tree  end----------------\n");
}
int viewTree(searchTree *p) {
    int f=-1,lc=-1,rc=-1;
    if ( p == NULL) { 
        printf("tree is empty\n"); 
        return 0;
    }
    f = p->val;
    //if ( p->lch == NULL) printf("p->lch is NULL\n");
    //if ( p->rch == NULL) printf("p->rch is NULL\n");
    if ( p->lch != NULL) lc = p->lch->val;
    if ( p->rch != NULL) rc = p->rch->val;
    printf("f=%4d,lchild=%4d,rchild=%4d\n",f,lc,rc);
    if ( p->lch != NULL) viewTree(p->lch);
    if ( p->rch != NULL) viewTree(p->rch);
    return 0;
}

int test_main() {
    //searchTree *p=NULL;
    g_p = insert(g_p,10);
    g_p = insert(g_p,30);
    g_p = insert(g_p,8);
    g_p = delete(g_p,6);
    g_p = delete(g_p,8);
    printf("*****************\n");
    treeView(g_p);


}

int getcommand(){
    char cmd=0;
    int n=-1;
//  searchTree *q = g_p;
    scanf(" %[ifdq]",&cmd);
    printf("cmd:%c\n",cmd);
    if ( cmd == 0) return 1;
    if ( cmd == 'q') return 88;
    scanf(" %d",&n);
    printf("n:%d\n",n);
    if ( n < 0 ) return 2; 
    return 0;
}

int docmd(char cmd , int n) {
    printf("start cmd %c n:%d\n",cmd,n);
    switch ( cmd ) {
        case 'i': g_p = insert( g_p, n); break;
        case 'd': g_p = delete( g_p, n); break;
        case 'f': if (find (g_p,n)) printf("%d found.\n",n); 
                  else printf("%d not found.\n",n); break;
        default: printf("cmd %c not supported.\n",cmd);
    }
    printf("done cmd %c n:%d\n",cmd,n);
}

int main() {
    int j=0,ii;
    int i[10] = { 3,6,8,2,1,4,9,7,5,10};
    int f[20] = { 5,11,1,12,8,13,2,14,3,14,4,15,6,16,7,17,9,19,10,20};
    int d[10] = { 1,4,7,9,8,5,3,10,6,2};
    for ( j = 0; j < 10; j++ ) {
        g_p = insert(g_p,i[j]);
    }
    treeView(g_p);
    for ( j = 0; j < 20; j++ ) {
        ii=find(g_p,f[j]);
        if(ii) printf("found %d\n",f[j]);
        else printf("not found %d\n",f[j]);
    }
    treeView(g_p);
    for ( j = 0; j < 10; j++ ) {
        g_p = delete(g_p,d[j]);
        printf("delete %d\n",d[j]);
        treeView(g_p);
    }
    treeView(g_p);
    printf("done\n");
}
