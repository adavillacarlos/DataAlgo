#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node nodeptr;
struct node {
	int coef;
	int exp;
	nodeptr next;
};

typedef nodeptr Polynomial;

// functions
Polynomial newPoly(); // allocate return the pointer to a header node

void destroyPoly(Polynomial *poly); // set to NULL after freeing

// there should be no multiple exponents
// when adding a new term, add the value to the coef for same exponents
void addTerm(Polynomial poly,int coef,int exp);

// display in decending order of exponents
void display(const Polynomial poly);

// return a new polynomial that represents the sum of poly1 and poly2
Polynomial add(const Polynomial poly1,const Polynomial poly22);

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial poly1,const Polynomial poly2);

// return a new polynomial that represents the product of p1 and p2
Polynomial multiply(const Polynomial poly1,const Polynomial poly2);

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial poly);

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial poly,int x);

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial poly);

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial poly);


int main(){
	
	
	return 0; 
}


Polynomial newPoly(){
	
} // allocate return the pointer to a header node

void destroyPoly(Polynomial *poly){


} // set to NULL after freeing

// there should be no multiple exponents
// when adding a new term, add the value to the coef for same exponents
void addTerm(Polynomial poly,int coef,int exp){
	
}

// display in decending order of exponents
void display(const Polynomial poly){
	
}

// return a new polynomial that represents the sum of poly1 and poly2
Polynomial add(const Polynomial poly1,const Polynomial poly22){
	
}

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial poly1,const Polynomial poly2){
	
}

// return a new polynomial that represents the product of p1 and p2
Polynomial multiply(const Polynomial poly1,const Polynomial poly2){
	
}

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial poly){
	
}

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial poly,int x){
	
}

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial poly){
	
}

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial poly){
	
}

