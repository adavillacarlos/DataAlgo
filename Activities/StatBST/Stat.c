#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stat.h"


treeptr createNode(int item){
    treeptr temp = (treeptr) malloc(sizeof(struct tnode));
    temp->item = item; 
    temp->left = temp->right = NULL;
    return temp;
}

int countNodes(treeptr t){
    if (t!=NULL) 
        return 1 + countNodes(t->left) + countNodes(t->right);
    else
        return 0;
}

void addInTree(treeptr t,int x){
    treeptr temp = createNode(x);
    treeptr p = t;
    treeptr prev = t;
    while (p!=NULL) {
        prev = p;
        if (x < p->item)
            p = p->left;
        else 
            p = p->right;
    }
    if (x < prev->item)
        prev->left = temp;
    else
        prev->right = temp;
}

void inDisplay(treeptr t){
    if (t!=NULL) {
		inDisplay(t->left);   
		printf("%d ",t->item);
		inDisplay(t->right);
	}
}


//Implement these functions
int findMinInTree(treeptr t){
    if(t->left!=NULL)
        return findMinInTree(t->left); 
    else
        return t->item; 
}
 // assume not empty
int findMaxInTree(treeptr t){
    if(t->right!=NULL)
        return findMaxInTree(t->right);
    else   
        return t->item;
}
 // assume not empty
int findSumInTree(treeptr t){
    if(t==NULL)
        return 0;
    else 
        return t->item + findSumInTree(t->left) + findSumInTree(t->right);
}

int freqInTree(treeptr t,int x){
 if(t==NULL)
		return 0; 
	else if(x<t->item)
		return (t->item==x) + freqInTree(t->left,x); 
    else
        return (t->item==x) + freqInTree(t->right,x);
}

int containsInTree(treeptr t,int x){
    if(t==NULL)
		return 0; 
	else if (x<t->item)
		return (t->item==x) || containsInTree(t->left,x);
	else 
		return (t->item==x)  || containsInTree(t->right,x);
}

void clearTree(treeptr t){
    if(t!=NULL){
        clearTree(t->left); 
        clearTree(t->right);
        free(t); 
    }
}

// void findItemAt(treeptr t,int mid,int *pos,int *item){}

Stat newStat(){
    Stat s =(Stat) malloc(sizeof(struct stat));
    s->root = NULL;
    return s; 
}

void destroy(Stat *s){
    clear(*s);
    free(*s);
    *s = NULL; 
}

void add(Stat s,int x){
    if(s->root == NULL)
        s->root = createNode(x);
    else
        addInTree(s->root,x);
}

void display(const char *name,Stat s){
    printf("%s = [ ", name);
    inDisplay(s->root);
    printf("]\n");
}

int getCount(Stat s){
    return countNodes(s->root);
}

int findMin(Stat s){
    return findMinInTree(s->root); 
}

int findMax(Stat s){
    return findMaxInTree(s->root);
}

int findRange(Stat s){
    return findMax(s) - findMin(s);  
}

int findSum(Stat s){
    return findSumInTree(s->root);
}

float findMean(Stat s){
    return (float) findSum(s) / getCount(s); 
}

float findMedian(Stat s){
    int count = getCount(s);
    int arr[count]; 
    int i=0; 
    int mid = count/2;
    makeArray(s->root,arr,i); 
    if(count%2==0)
        return (arr[mid] + arr[mid-1]) / 2.0;
    else
        return arr[mid];
}

int makeArray(treeptr t, int arr[], int i){
    if(t==NULL)
        return i; 
    i = makeArray(t->left,arr,i); 
    arr[i++] = t->item; 
    i = makeArray(t->right,arr,i);
    return i; 
}

int contains(Stat s,int x){
    return containsInTree(s->root,x) != 0;
}

int frequency(Stat s,int x){
    return freqInTree(s->root,x);
}

int isEmpty(Stat s){
    return countNodes(s->root) == 0; 
}

void clear(Stat s){
    if(s->root!=NULL){
        clearTree(s->root);
        s->root =NULL; 
    }
    
}

float standardDeviation(Stat s){
    float mean = findMean(s); 
    float sum = SDinTree(s->root,mean); 
    float down = countNodes(s->root) -1;
    return sqrt(sum/down);
}

float SDinTree(treeptr t,float mean){
        if(t==NULL)
            return 0;
        else
            return pow((t->item - mean), 2) + SDinTree(t->left,mean) + SDinTree(t->right,mean);  
}
