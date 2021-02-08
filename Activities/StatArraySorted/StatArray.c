#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StatArray.h"


StatArray newStatArray(){
	StatArray s = (StatArray) malloc(sizeof(struct stat));
	s->size = 10;
	s->items = (int *) malloc(sizeof(int)*s->size);
	s->count = 0;
	return s;	
}

void destroy(StatArray *s){
    free((*s)->items);
    free(*s); 
    *s = NULL;
}

void addLast(StatArray s, int elem){
	int i=0,j; 
	int temp; 
	if ((s->count < s->size) || doubleTheSize(s))  { 
		s->items[s->count++] = elem;
	}
}

void add(StatArray s, int elem){
//    int i; 
//    int p=-1; 
//
//    if(s->count < s->size || doubleTheSize(s)){
//        //did not used binary search since there is a chance that it would return the mid
//        //of num. who has a lot of frequency. 
//        for(i=0;i<s->count;i++){
//            if(elem<s->items[i]){
//                p=i; 
//                break; 
//            }
//        }
//        if(p!=-1){
//            for(i=s->count;i>p;i--){
//                s->items[i] = s->items[i-1]; 
//            }
//            s->items[p] = elem;   
//            s->count++;
//        } else{
//		    s->items[s->count++] = elem;
//        }
//    }
    
    int i; 
    if((s->count < s->size) || doubleTheSize(s)){
    	for(i=s->count ; i>0;i--){
    		if(elem>s->items[i-1])
    			break; 
    		else
    			s->items[i] = s->items[i-1]; 
		}
		s->items[i] = elem;
		s->count++;
	}

}


void display(const char *name,const StatArray s){
    int i; 
    printf("%s = [ ",name);
    for(i=0;i<s->count;i++){
        printf("%d ",s->items[i]);
    }
    printf("]\n");
}

void clear(StatArray s){
    s->count=0;
}

int isEmpty(const StatArray s){
    return s->count==0;
}

int contains(StatArray s, int elem){
 	return binarySearch(s,elem,0,s->count) != -1;
}

int frequency(StatArray s, int elem){
    int i; 
    int freq=0; 
    for(i=0;i<s->count;i++){
        if(s->items[i]==elem)
            freq++;
    }
    return freq;
}

int getCount(const StatArray s){
    return s->count;
}

int findMin(const StatArray s){
    return s->items[0];
}

int findMax(const StatArray s){
    return s->items[s->count-1];
}

int findRange(const StatArray s){
    return findMax(s) - findMin(s);
}

float findMedian(const StatArray s){
    if(s->count%2!=0)
        return s->items[s->count/2];
    else
        return ((s->items[s->count/2] + s->items[s->count/2 -1]) /2.0); 
}

int findSum(const StatArray s){
    int sum = 0; 
    int i; 
    for(i=0;i<s->count;i++){
        sum+=s->items[i];
    }
    return sum; 
}

float findMean(const StatArray s){
    return (float)findSum(s)/ (float)s->count;	
}

float findStandardDeviation(const StatArray s){
   int i;
   float up = 0; 
   float mean = findMean(s);
   for(i=0;i<s->count;i++){
       up += pow(((float)s->items[i] - mean), 2); 
   }
   return sqrt(up/(s->count-1)); 

}

//implement remove such that, when you find the item to be removed
// replace it with the last xent
void removeFirst(StatArray s, int x){
    int i; 
    int pos = binarySearch(s,x,0,s->count);
    if(pos!=-1){
        for(i=pos; i<s->count;i++){
            s->items[i] = s->items[i+1]; 
        }
        s->count--;
    }
}

//remove all occurrences, same strategy as removeFirst
void removeAll(StatArray s, int x){
    int i; 
    int freq = frequency(s,x);
    for(i=0;i<freq;i++){
        removeFirst(s,x);
    }
}

int doubleTheSize(StatArray s){
	int *temp;
	int flag = 0;
	int count = 2;
    int i; 
	temp = (int *) malloc(sizeof(int)*s->size*count);
	if (temp != NULL) {
		s->size *= count;
		for (i=0; i < s->count; i++)	
			temp[i] = s->items[i];
		free(s->items);
		s->items = temp;
		flag = 1;
	}
	return flag;
}

int binarySearch(const StatArray s,int x,int first,int last){
	int mid;
	//instead of return 1, return mid to get the index.then return -1 for the 0;
	if (first <= last) { // at least one element
		mid = (first + last) / 2;
		if (x == s->items[mid] )
			return mid;
		else 
		if (x < s->items[mid])
			return binarySearch(s,x,first,mid-1);
		else
			return binarySearch(s,x,mid+1,last);
	}
	else
		return -1;	
}

int findFirstPos(StatArray s, int x){
	int i, pos = binarySearch(s, x, 0, s->count-1);
	for(i=pos-1; i>=0;i--){
	if(s->items[i]!=x)
		break; 
	}
	return i+1;
}
