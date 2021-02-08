#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "StatArray.h"

//implement the functions here

int findPos(StatArray s, int x) {
	int pos = -1;
	for (int i=0; i < s->count; i++) {
		if (s->items[i] == x) {
			pos = i; break;
		}			
	}
	return pos;
}

int doubleTheSize1(StatArray s){
	int *temp;
	int success = 0;
	int count = 2;
	temp = (int *) malloc(sizeof(int)*s->size*count);
	if (temp != NULL) {
		s->size *= count;
		for (int i=0; i < s->count; i++)	
			temp[i] = s->items[i];
		free(s->items);
		s->items = temp;
		success = 1;
	}
	return success;
}

// using realloc
int doubleTheSize2(StatArray s){
	int *temp;
	int success = 0;
	int count = 2;
	temp = (int *) realloc(s->items,sizeof(int)*s->size*count);
	if (temp != NULL) {
		s->items = temp;
		s->size *= count;
		success = 1;
	}
	return success;
}


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

void add(StatArray s, int elem){
	int i=0,j; 
	int temp; 
	if ((s->count < s->size) || doubleTheSize1(s))  { 
		s->items[s->count++] = x;
		
	}
	
//for sorting
//		for(i=0;i<s->count;i++){
//			for(j=i;j>0;j--){
//				if(s->items[j-1] > s->items[j]){
//					temp = s->items[j-1]; 
//					s->items[j-1] = s->items[j];
//					s->items[j] = temp;
//				}
//			}
//		}		
	//or 
//	s->items[s->count++] = x;
//	i = arr.length - 1;
//    item = arr[i];
//
//	while (i > 0 && item < arr[i-1]) {
//	        arr[i] = arr[i-1];
//	        i -= 1;
//	    }
//	    arr[i] = item;

    
//	if(s->count < s->size){
//        s->items[s->count++]=elem;
//    }
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
    int i; 
    for(i=0;i<s->count;i++){
        s->items[i]=0; 
    }
    //s->count=0;
}
int isEmpty(const StatArray s){
   	return s->count==0;
}
int contains(StatArray s, int elem){
 	return findPos(s,x) != -1;
}

int frequency(StatArray s, int elem){
    int i; 
    int freq=0; 
    for(i=0;i<s->count;i++){
        if(s->items[i]==elem)
            freq++;
    }
    return freq;
} // number of occurrences of elem

int getCount(const StatArray s){
    return s->count;
}

int findMin(const StatArray s){
    int min = s->items[0]; 
    int i; 
    for(i=0;i<s->count;i++){
        if(s->items[i]<min){
            min = s->items[i]; 
        }
    }
    return min; 
    //return s->items[s->count-1]; 
}

int findMax(const StatArray s){
    int max = s->items[0]; 
    int i; 
    for(i=0;i<s->count;i++){
        if(s->items[i]>max){
            max = s->items[i]; 
        }
    }
    return max; 
    //return s->items[s->count-1]; 

}

int findRange(const StatArray s){
    return findMax(s) - findMin(s); 
}

int findSum(const StatArray s){
    int i; 
    int sum = 0; 
    for(i=0;i<s->count;i++){
        sum+=s->items[i]; 
    }
    return sum; 
}

float findMean(const StatArray s){
//    int sum = findSum(s); 
//    float mean = (float) sum / s->count;
//    return mean; 
    return (float)findSum(s)/ (float)s->count;	

}

float findStandardDeviation(const StatArray s){
//    int i;
//    float up = 0; 
//    float mean = findMean(s);
//    for(i=0;i<s->count;i++){
//        up += pow(((float)s->items[i] - mean), 2); 
//    }
//    float sd = sqrt(up/(s->count-1));
//    return sd; 
	float mean = findMean(s);
    float temp;
	float sum = 0;
	for (int i=0; i < s->count; i++) {
        temp = (s->items[i] - mean);
		sum += temp * temp;
	}
	return (float)sqrt(sum/(s->count-1));
}

void removeFirst(StatArray s, int x){
	int pos = findPos(s,x);
	if (pos != -1) {
		s->items[pos] = s->items[--s->count];
	}	
//    int i; 
//    for(i=0;i<s->count;i++){
//        if(x==s->items[i]){
//            s->items[i] = s->items[s->count-1]; 
//            s->items[s->count-1]=0; 
//            (s->count)--; 
//            break; 
//        }
//    }
}

void removeAll(StatArray s, int x){
//    int i;
//    int freq = frequency(s,x);
//    for(i=0;i<freq;i++){
//        if(contains(s,x)){
//            removeFirst(s,x);
//        }
//    }
	for (int i=0; i < s->count; ) {
		if (s->items[i] == x) {
			s->items[i] = s->items[--s->count];
			continue;
		}
		else i++;
	}	
}
