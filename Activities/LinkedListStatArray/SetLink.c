#include <stdio.h>
#include <stdlib.h>
#include "SetLink.h"

nodeptr createNode(int item) {
	nodeptr temp;
	temp = (nodeptr) malloc(sizeof(struct node));
	temp->item =item;
	temp->next = NULL;
	return temp;
}

SetLink newSetLink(){
	return createNode(0);	
}

void add(SetLink s,int elem){
    if(!contains(s,elem)){
        nodeptr temp = createNode(elem);
        nodeptr p = s; 
        while(p->next!=NULL)
            p = p->next; 
        p->next = temp; 
    }
}

void display(const char *name,const SetLink s){
	nodeptr p = s->next;
	printf("%s = { ",name);
	while (p!=NULL) {
		printf("%d ",p->item);
		p=p->next;
	}
	printf("}\n");	
}

void removeIt(SetLink s,int elem){
    nodeptr prev = s; 
    nodeptr p = s->next; 
    if(p!=NULL){
        while(p!=NULL){
            if(p->item==elem){
                prev->next = p->next; 
                free(p);
                break; 
            }
            prev = p; 
            p = p->next;
        }
    }
}

void destroy(SetLink *s){
    clear(*s);
    free(*s); 
}

int contains(const SetLink s,int elem){
    nodeptr p = s->next;
    int flag=0; 
    if(p!=NULL){
        while(p!=NULL){
            if(p->item == elem){
                flag=1; 
                break; 
            }
            p = p->next; 
        }
    }
    return flag; 
}

int cardinality(const SetLink s){
    int ans=0;
    nodeptr p = s->next;
    while(p!=NULL){
        ans++; 
        p=p->next; 
    }
    return ans; 
}

int isEmpty(const SetLink s){
    return s->next == NULL;
}

void clear(SetLink s){
    nodeptr p = s->next; 
    nodeptr temp; 
    while(p!=NULL){
        temp = p; 
        p = p->next;
        free(temp);
    }
    s->next = NULL; 
}

int isSubset(const SetLink s1,const SetLink s2){
    nodeptr p1 = s1->next; 
    int flag=1; 
    while(p1!=NULL){
        if(!contains(s2,p1->item)){
            flag=0;
            break; 
        }
        p1 = p1->next; 
    }
    return flag; 
}

int areDisjoint(const SetLink s1,const SetLink s2){
    nodeptr p2 = s2->next; 
    int flag=1; 
    while(p2!=NULL){
        if(contains(s1,p2->item)){
            flag=0;
            break; 
        }
        p2 = p2->next; 
    }
    return flag; 
}

SetLink getUnion(const SetLink s1,const SetLink s2){
    nodeptr p1 = s1->next; 
    nodeptr p2 = s2->next; 
    SetLink result = newSetLink(); 
    while(p1!=NULL){
        add(result,p1->item);
        p1 = p1->next; 
    }
     while(p2!=NULL){
        add(result,p2->item);
        p2 = p2->next; 
    }
    return result;
}

SetLink getIntersection(const SetLink s1,const SetLink s2){
    nodeptr p1 = s1->next; 
    SetLink result = newSetLink(); 
    while(p1!=NULL){
        if(contains(s2,p1->item)){
            add(result,p1->item); 
        } 
        p1 = p1->next;
    }
    return result;
}

SetLink getDifference(const SetLink s1,const SetLink s2){
    nodeptr p1 = s1->next; 
    SetLink result = newSetLink(); 
    while(p1!=NULL){
        if(!contains(s2,p1->item)){
            add(result,p1->item); 
        } 
        p1 = p1->next;
    }
    return result;
}
