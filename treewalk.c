#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * _                               _ _    
 * | |                             | | |   
 * | |_ _ __ ___  _____      ____ _| | | __
 * | __| '__/ _ \/ _ \ \ /\ / / _` | | |/ /
 * | |_| | |  __/  __/\ V  V / (_| | |   < 
 *  \__|_|  \___|\___| \_/\_/ \__,_|_|_|\_\
 *
*/

struct tnode {         // tree structure node type
  int i;               // primary index
  int j;               // character count of token
  char *a;             // token
  struct tnode *l;     // left pointer
  struct tnode *r;     // right pointer
} *fh,                 // fixed_head
  *rh;                 // read_head
/*

    // apparently you can't do this??: 
    struct tnode *fh;  //fixed_head
    struct tnode *rh;  //read_head
*/



struct tnode *talloc(int x, char *a){
    struct tnode *ptr;
    int i;
    ptr =  (struct tnode *) malloc(sizeof(struct tnode));
    ptr->a = (char *) malloc(strlen(a)); 
    ptr->i = x;
    ptr->j = strlen(a);
    ptr->l = NULL;
    ptr->r = NULL;
    for(i=0; i<strlen(a); i++) ptr->a[i] = a[i]; 
    return ptr;
}


void walktree(struct tnode * ptr){
    while (ptr != NULL){
        printf("\n token # = %i string = %s sizeof string = %i\n\n", 
               ptr->i, ptr->a, ptr->j);
        ptr = ptr->r;
    }
}


treewalk(){
    int x = 0;
    struct tnode *root;
    char buf[20];

    root = talloc(x,"test0");
    fh = root;
    for(x = 8; x < 12; x++){
        sprintf(buf, "test%i",x);
        rh = talloc(x, buf);
        printf("\n token # = %i string = %s sizeof string = %i\n\n", 
               rh->i, rh->a, rh->j);
        fh->r = rh;
        fh = rh;
    }
    walktree(root);
}
