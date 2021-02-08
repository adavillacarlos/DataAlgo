#include <stdio.h>
#include <stdlib.h>
#include <Math.h>

#define MAX 10

typedef  int* Polynomial;

//functions
Polynomial newPoly(); // allocate return the pointer
void destroyPoly(Polynomial *p); // set to NULL after freeing ; output parameter

void addTerm(Polynomial p,int coef,int exp); //output parameter
void display(const Polynomial p); //input parameter

// return a new polynomial that represents the sum of p1 and p2 ; input parameter
Polynomial add(const Polynomial p1,const Polynomial p2 );

// return a new polynomial that represents the difference of p1 and p2; input parameter
Polynomial subtract(const Polynomial p1,const Polynomial p2 );

// return a new polynomial that represents the derivative of p1 ; input parameter
Polynomial derivative(const Polynomial p);

// compute the value of the polynomial given a value for x; input parameter 
int evaluate(const Polynomial p,int x);

// return 1 if the value of p is constant, 0 otherwise; input parameter 
int isConstant(const Polynomial p);

// return 1 if the value of p is zero (0), 0 otherwise; input parameter
int isZero(const Polynomial p);

// return 1 if there is coefficient for all exponents, 0 otherwise; input parameter
int isComplete(const Polynomial p);

int main(){
	Polynomial p1 = newPoly();
	Polynomial p2 = newPoly();
	Polynomial p3; 
	Polynomial p4 = newPoly();
	
	//Adding terms to p1
	addTerm(p1,1,9);
	addTerm(p1,2,8);
	addTerm(p1,3,7);
	addTerm(p1,-4,6);
	addTerm(p1,3,5);
	addTerm(p1,-2,4);
	addTerm(p1,7,3);
	addTerm(p1,3,2);
	addTerm(p1,1,1);
	addTerm(p1,8,0);
	
	//Adding terms to p2
	addTerm(p2,1,9);
	addTerm(p2,-2,8);
	addTerm(p2,3,7);

	printf("P1: ");
	display(p1);
	printf("P2: ");
	display(p2);
	
	p3 = add(p1,p2); 
	printf("P1 + P2 = ");
	display(p3);
	destroyPoly(&p3);
	
	printf("P1 - P2 = ");
	p3 = subtract(p1,p2);
	display(p3);
	destroyPoly(&p3);

	printf("\nDerivative of P1: ") ;
	p3 = derivative(p1); 
	display(p3);
	destroyPoly(&p3);
	
	printf("\nValue of P1 when x= 3: %d",evaluate(p1,3));
	printf("\nValue of P2 when x= 1: %d",evaluate(p2,2));
	printf("\nIs P1 Constant:  %d", isConstant(p1));
	printf("\nIs P1 Zero: %d", isZero(p1));
	printf("\nIs P1 Complete: %d", isComplete(p1));
	
	//P4
	addTerm(p4,0,0);
	printf("\n\nP4: ");
	display(p4);
	printf("Is P4 Constant:  %d", isConstant(p4));
	printf("\nIs P4 Zero: %d", isZero(p4));
	printf("\nIs P4 Complete: %d", isComplete(p4));

	//Deallocating the remaining arrays
	destroyPoly(&p1);
	destroyPoly(&p2);
	destroyPoly(&p4);

	if(p1==NULL && p2==NULL && p3==NULL && p4==NULL)
		printf("\n\nArrays are all null");

	return 0; 
}

Polynomial newPoly(){
	Polynomial poly = (Polynomial) calloc(MAX,sizeof(int));
	return poly;
}

void destroyPoly(Polynomial *p){
	free(*p);
	*p=NULL;
}

void addTerm(Polynomial p,int coef,int exp){
	if(exp>=0 && exp<10)
		p[exp] = coef;
	else
		printf("%d as an exponent is not allowed\n",exp);
}

void display(const Polynomial p){
	int i; 
	int flag=0;
	for(i=0;i<MAX;i++){	
		if(p[i]!=0){
			if(p[i]>0 && flag==1){
				printf(" + ");
			} else if (p[i]<0 && flag!=0){
				printf(" - ");
			}

			if(p[i]==1 && i==0 || p[i]!=1){
                if(flag==1)
                    printf("%d",abs(p[i]));	
                else   
                    printf("%d",p[i]);	
            }
			flag=1;	
			if(i==1)
				printf("x");
			else if (i!=0)
				printf("x^%d",i);
		}
	}
	
	if(flag==0)
		printf("0");
    
    printf("\n");
}

Polynomial add(const Polynomial p1,const Polynomial p2 ){
	Polynomial result = newPoly();
	int i; 
	for(i=0;i<MAX;i++){
		if(p1[i]!=0 || p2[i]!=0)
			result[i] = p1[i]+p2[i];
	}
	return result; 
}

Polynomial subtract(const Polynomial p1,const Polynomial p2 ){
	Polynomial result = newPoly();
	int i; 
	for(i=0;i<MAX;i++){
		if(p1[i]!=0 || p2[i]!=0)
			result[i] = p1[i]-p2[i];
	}
	return result; 
}

Polynomial derivative(const Polynomial p){
	Polynomial result = newPoly(); 
	int i;
	for(i=1;i<MAX;i++){
		if(p[i]!=0){
			result[i-1] = p[i]*i;
		}
	}
	return result; 
}

int evaluate(const Polynomial p,int x){
	int i; 
	int ans=0;
	for(i=0;i<MAX;i++){
		ans += pow(x,i) * p[i];
	}
	return ans;
}

int isConstant(const Polynomial p){
	int i; 
	int flag=1;
	for(i=1;i<MAX;i++){
		if(p[i]!=0){
			flag=0;
			break;  
		}
	}
	return flag;
}

int isZero(const Polynomial p){
	int flag=1;
	int i;
	for(i=0;i<MAX;i++){
		if(p[i]!=0){
			flag=0;
			break; 
		}
	}
	return flag;	
}

int isComplete(const Polynomial p){
	int flag=1;
	int i; 
	for(i=0;i<MAX;i++){
		if(p[i]==0){
			flag=0;
			break; 
		}
	}
	return flag;
}
