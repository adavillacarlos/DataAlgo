#include <stdio.h>
#include <stdlib.h>

#define MAX 100
void display (int *arr, const char *name); 
int findSum(int *arr); 
void initialize(int *arr,int n);

int main(){
	int *array1; 
	int *array2; 
	int *array3; 
	
	array1 = (int *) malloc(sizeof(int)*MAX); 
	printf("\nadd of array 1: %0X",array1); 
	initialize(array1,2); 
	printf("\nSum of array 1 = %d",findSum(array1)); 
	//Array 2 is an alias - another name for another memory location
	array2=array1; 
	printf("\nadd of array 2: %0X",array2); 
	
	//if you set an array1=NULL, it is not yet garbage
	//bec array2 to array1 but if you set both to NULL then it would become garbage.
	
//	free(array1); //array1 & array2 are dangling reference
	array3 = (int *)malloc(sizeof(int)*MAX); 
	printf("\nadd of arr 3: %0X",array3); 
	initialize(array3,3); 
	printf("\nSum of array 3 = %d",findSum(array3)); 
	printf("\nSum of array 2 = %d",findSum(array2)); 

	
	
	return 0; 
}

void display (int *arr, const char *name){
	int i; 
	printf("\n%s\n",name); 
	for(i=0;i<MAX;i++){
		printf("[%d] = %d\n",i,arr[i]);
	}
}

void initialize(int *arr, int n){
	int i;
	for(i=0;i<MAX;i++){
		arr[i]=1;
		arr[i]*=n; 
	}
}

int findSum(int *arr){
	int sum=0; 
	int i; 
	for(i=0;i<MAX;i++){
		sum+=arr[i]; 
	}
	return sum; 
}
