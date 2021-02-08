#include <stdio.h>
#include <stdlib.h>

typedef struct node *nodeptr;
struct node {
    int item;
    nodeptr next;
};

typedef nodeptr IntList;

IntList newIntList(); // create header node
void destroy(IntList *list);
void clear(IntList list);
void addFront(IntList list,int x);
void addRear(IntList list,int x);
void removeFront(IntList list);
void removeRear(IntList list);
void display(const char *name,const IntList list);
void removeIt(IntList list,int x);

// implement these functions for practice
int contains(const IntList list,int x);
int frequency(const IntList list,int x);
int findSum(const IntList list);

void removeAll(IntList list,int x); // remove all occurences of x
void removeAllNegative(IntList list); 

// returns the item of the node at position pos
// example getItemAtPos(list,1) - will return the first item
// example getItemAtPos(list,5) - will return the fifth item
// assume that pos is a valid value
int getItemAt(IntList list,int pos);

// remove the node at position pos
// example removeItemAtPos(list,1) - will remove first node
// example removeItemAtPos(list,5) - will remove the fifth node
void removeItemAtPos(IntList list,int pos);

//helper functions
int findPos(const IntList list, int x);

int main(){

    IntList list = newIntList();
	addRear(list,100);
	removeIt(list,100);
	display("list",list);
    addRear(list,100);
    addRear(list,-200);
	display("list",list);
	clear(list);
	display("list",list);

	addFront(list,100);
    addRear(list,100);
    display("list",list);

//	printf("%d\n", findPos(list,-200));
//	removeAll(list,100);
//	display("list",list);
//    display("list",list);
//    addFront(list,10);
//    addFront(list,20);
//    addFront(list,30);
//    addFront(list,40);
//    display("list",list);
//    removeIt(list,20);
//    display("list",list);
//    removeIt(list,40);
//    display("list",list);
    
    return 0;
}


// private
nodeptr createNode(int x) {
    nodeptr temp = (nodeptr) malloc(sizeof(struct node));
    temp->item = x;
    temp->next = NULL;
    return temp;
}

IntList newIntList() { // create header node
    return createNode(0); // header
}


void destroy(IntList *list){
    clear(*list); //becomes empty
    free(*list); // free header node
}

//not sure. 
void clear(IntList list){
	nodeptr p = list->next;
	nodeptr temp;
	while(p!=NULL){
		temp = p; 
		p = p->next;
		free(temp);
	}
	list->next = NULL;
}

void addFront(IntList list,int x){
    nodeptr temp = createNode(x);
    temp->next = list->next;
    list->next = temp;
}

void removeFront(IntList list) {
    nodeptr temp = list->next;
    if (temp != NULL) {
        list->next = temp->next;
        free(temp);
    }
}

void addRear(IntList list,int x) {
    nodeptr temp = createNode(x);
    nodeptr p = list;
    while (p->next != NULL) {
         p=p->next;
    }
    p->next = temp;
}

void removeRear(IntList list){
    nodeptr prev = list;
    nodeptr p = list->next;
    if (p!=NULL) { // not empty
        while (p->next!=NULL) {
               prev = p; // prev = prev->next
               p = p->next; 
        }
        free(p);
        prev->next = NULL;
    }
}


void display(const char *name,const IntList list){
    nodeptr p = list->next;
    printf("%s = [",name);
    while (p!=NULL) {
        printf("%d ",p->item);
        p=p->next;
    }
    printf("]\n");
}


// removes occurrence
void removeIt(IntList list,int x){
    nodeptr prev = list;
    nodeptr p = list->next;
    if(p!=NULL){
    	while (p!=NULL) {
	        if (p->item == x) { // found it
	            prev->next = p->next;
	            free(p);
	            break;
	        }
	        prev = p;
	        p = p->next;
    	}
	}
   
}


// implement these functions for practice
int contains(const IntList list,int x){
//	nodeptr p = list->next; 
//	int flag=-1;
//	while(p!=NULL){
//		if(p->item==x){
//			flag=1; 
//			break; 
//		}
//		p = p->next; 
//	}
//	return flag; 
	return findPos(list,x) != -1;
}

int frequency(const IntList list,int x){
	nodeptr p = list->next;
	int freq=0; 
	while(p!=NULL){
		if(p->item==x)
			freq++; 
		p = p->next;
	}
	return freq; 
}

int findSum(const IntList list){
	int sum=0;
	nodeptr p = list->next; 
	while(p!=NULL){
		sum+=p->item; 
		p = p->next;
	}
	return sum; 
}

void removeAll(IntList list,int x){
	nodeptr p = list->next; 
	nodeptr prev = list; 
	if(p!=NULL){
		while(p!=NULL){
		if(p->item==x){ 
			prev->next = p->next;
			free(p); 
			p=prev;
		}
		prev = p; 
		p = p->next;	
	}
	}


} // remove all occurences of x

void removeAllNegative(IntList list){
nodeptr p = list->next; 
	nodeptr prev = list; 
	
	while(p!=NULL){
		if(p->item<=-1){ 
			prev->next = p->next;
			free(p); 
			p=prev;
		}
		prev = p; 
		p = p->next;	
	}
}


// returns the item of the node at position pos
// example getItemAtPos(list,1) - will return the first item
// example getItemAtPos(list,5) - will return the fifth item
// assume that pos is a valid value
int getItemAt(IntList list,int pos){
	nodeptr p = list->next; 
	int i=1; 
	int ans = -1; 
	while(p!=NULL){
		if(i==pos){
			ans = p->item; 
			break; 
		}
		i++;
		p = p->next; 
	}
	return ans; 
}

// remove the node at position pos
// example removeItemAtPos(list,1) - will remove first node
// example removeItemAtPos(list,5) - will remove the fifth node
void removeItemAtPos(IntList list,int pos){
	nodeptr prev = list;
    nodeptr p = list->next;
    int i=1;
    while (p!=NULL) {
    	if(i==pos){// found it
	        prev->next = p->next;
	        free(p);
	        break;
        }
        i++;
        prev = p;
        p = p->next;
	}
		
}


int findPos(const IntList list, int x){
	nodeptr p = list->next; 
	int flag=-1;
	int i=1;
	while(p!=NULL){
		if(p->item==x){
			flag=i; 
			break; 
		}
		i++;
		p = p->next; 
	}
	return flag; 
}


//SetArray
//
//
//int isEmpty(const SetArray s){
//	int flag=1; 
//	int i; 
//	for(i=0;i<s->count;i++){
//		if(s->items[i]!=0){
//			flag=0;
//			break;  
//		}
//	}
//	return flag; 
//}
//
//int contains(SetArray s, int elem){
//	int flag=0;
//	int i;
//	for(i=0;i<s->count;i++){
//		if(s->items[i]==elem){
//			flag=1; 
//			break; 
//		}
//	}
//	return flag; 
//}
//
//int cardinality(const SetArray s){
//	return s->count;
//}
//
//SetArray getUnion(const SetArray s1,const SetArray s2){
//	SetArray result = newSetArray(); 
//	int i;
//	for(i=0;i<s1->count;i++){
//		add(result,s1->items[i]);
//	}
//	for(i=0;i<s2->count;i++){
//		add(result,s2->items[i]);
//	}
//	return result;
//}
//
//SetArray getIntersection(const SetArray s1,const SetArray s2){
//	SetArray result = newSetArray(); 
//	int i; 
//	for(i=0;i<s1->count;i++){
//		if(contains(s2,s1->items[i])){
//			add(result,s1->items[i]);
//		}
//	}
//	return result; 
//}
//
//SetArray getDifference(const SetArray s1,const SetArray s2){
//	SetArray result = newSetArray(); 
//	int i;
//	for(i=0;i<s1->count;i++){
//		if(!contains(s2,s1->items[i])){
//			add(result,s1->items[i]);
//		}
//	}
//	return result; 
//}
//
//int isSubset(const SetArray s1,const SetArray s2){
//	int flag=1; 
//	int i; 
//	for(i=0;i<s1->count;i++){
//		if(!contains(s2,s1->items[i])){
//			flag=0;
//			break; 
//		}
//	}
//	return flag; 
//}
//
//int areDisjoint(const SetArray s1,const SetArray s2){
//	int flag=1; 
//	int i; 
//	for(i=0;i<s2->count;i++){
//		if(contains(s1,s2->items[i])){
//			flag=0;
//			break; 
//		}
//	}
//	return flag;
//}
//
//
////implement remove such that, when you find the item to be removed
//// replace it with the last element
//void removeIt(SetArray s, int elem){
//	int i; 
//	for(i=0;i<s->count;i++){
//		if(elem==s->items[i]){
//			s->items[i] = s->items[s->count-1];
//            (s->count)--;
//			break; 
//		}
//	}
//}

