#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node *nodeptr;
struct node {
	int coef;
	int exp;
	nodeptr next;
};

typedef nodeptr Polynomial;

// functions
Polynomial newPoly(); // allocate return the pointer to a header node

void destroyPoly(Polynomial *poly); // set to NULL after freeing

void clear(Polynomial poly); 

// there should be no multiple exponents
// when adding a new term, add the value to the coef for same exponents
void addTerm(Polynomial poly,int coef,int exp);

// display in decending order of exponents
void display(const Polynomial poly);

// return a new polynomial that represents the sum of poly1 and poly2
Polynomial add(const Polynomial poly1,const Polynomial poly2);

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

int containsExponent(const Polynomial poly, int exp);
int findPosition(const Polynomial poly, int exp);
void multipleExponent(Polynomial poly, int coef, int exp);
void insertionSort(Polynomial poly, int coef, int exp);
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
	addTerm(p1,7,0);
	addTerm(p1,1,0);
	
	//Adding terms to p2
	addTerm(p2,1,9);
	addTerm(p2,-2,8);
	addTerm(p2,3,7);

	printf("P1: ");
	display(p1);
	printf("P2: ");
	display(p2);
	

	p3 = add(p1,p2); 
	printf("\nP1 + P2 = ");
	display(p3);
	destroyPoly(&p3);
	
	printf("P1 - P2 = ");
	p3 = subtract(p1,p2);
	display(p3);
	destroyPoly(&p3);
	
	p3 = multiply(p1,p2); 
	printf("P1 * P2 = ");
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
	
	//P4
	addTerm(p4,0,0);
	printf("\n\nP4: ");
	display(p4);
	printf("Is P4 Constant:  %d", isConstant(p4));
	printf("\nIs P4 Zero: %d", isZero(p4));

	//Deallocating the remaining arrays
	destroyPoly(&p1);
	destroyPoly(&p2);
	destroyPoly(&p4);

	if(p1==NULL && p2==NULL && p3==NULL && p4==NULL)
		printf("\n\nArrays are all null");
	return 0;
}

nodeptr createNode(int coef, int exp){
	nodeptr temp = (nodeptr) malloc(sizeof(struct node));
    temp->coef = coef;
    temp->exp = exp; 
    temp->next = NULL;
    return temp;
}

Polynomial newPoly(){
	return createNode(0,0); 
} // allocate return the pointer to a header node

void destroyPoly(Polynomial *poly){
	clear(*poly); 
	free(*poly);
	*poly = NULL;
} // set to NULL after freeing

void clear(Polynomial poly){
	nodeptr p = poly->next;
	nodeptr temp;
	while(p!=NULL){
		temp = p; 
		p = p->next;
		free(temp);
	}
	poly->next = NULL;
}

// there should be no multiple exponents
// when adding a new term, add the value to the coef for same exponents
void addTerm(Polynomial poly,int coef,int exp){
	nodeptr p = poly; 
	nodeptr temp;
	int pos; 
	int i=1; 
	if(containsExponent(poly,exp)){
		multipleExponent(poly,coef,exp);
	} else {
		temp = createNode(coef,exp);
		pos = findPosition(poly,exp);
		if(pos!=0){
			while(i<pos){
				p = p->next;
				i++;
			}	
		}
		temp->next = p->next; 
		p->next = temp;
	}
}

void multipleExponent(Polynomial poly, int coef, int exp){
	nodeptr p = poly->next;
	while(p!=NULL){
			if(p->exp == exp){
				p->coef+=coef; 
				break; 
			} 	
			p = p->next;
	}
}

int containsExponent(const Polynomial poly, int exp){
	nodeptr p = poly->next;
	int flag=0;  
	while(p!=NULL){
		if(exp==p->exp){
			flag=1;
			break; 
		}
		p = p->next;
	}
	return flag; 
}
int findPosition(const Polynomial poly, int exp){
	nodeptr p = poly;
	int flag=0;
	int i=1;  
	while(p!=NULL){
		if(exp<=p->exp){
			flag=i;
		}
		++i;
		p = p->next;
	}
	return flag; 
}

// display in descending order of exponents
void display(const Polynomial poly){
	int flag=0;
	nodeptr p = poly->next; 
	int i=0; 
	while(p!=NULL){
		if(p->coef!=0){
			if(p->coef>0 && flag==1){
				printf(" + ");
			} else if(p->coef<0 && flag!=0){
				printf(" - ");
			}
			
			if(p->coef==1 && p->exp==0 || p->coef!=1){
				if(flag==1)
					printf("%d",abs(p->coef));
				else
					printf("%d",p->coef);
			}
			
			if(p->exp==1)
				printf("x");
			else if(p->exp!=0)
				printf("x^%d",p->exp);
			
			flag=1;
		}
			p = p->next;
	}
	
	if(flag==0)
		printf("0");
    
    printf("\n");

}


// return a new polynomial that represents the sum of poly1 and poly2
Polynomial add(const Polynomial poly1,const Polynomial poly2){
	Polynomial result = newPoly();
	nodeptr p1 = poly1->next;
	nodeptr p2 = poly2->next;
	while(p1!=NULL){
		addTerm(result,p1->coef,p1->exp);
		p1=p1->next;
	}
	while(p2!=NULL){
		addTerm(result,p2->coef,p2->exp);
		p2=p2->next;
	}
	
	return result; 
}

// return a new polynomial that represents the difference of p1 and p2
Polynomial subtract(const Polynomial poly1,const Polynomial poly2){
	Polynomial result = newPoly();
	nodeptr p1 = poly1->next; 
	nodeptr p2 = poly2->next;
	while(p1!=NULL){
		addTerm(result,p1->coef,p1->exp);
		p1 = p1->next;
	}
	while(p2!=NULL){
		addTerm(result,p2->coef * -1, p2->exp); 
		p2 = p2->next;
	}
	return result;
}

// return a new polynomial that represents the product of p1 and p2
Polynomial multiply(const Polynomial poly1,const Polynomial poly2){
	Polynomial result = newPoly();
	nodeptr p1 = poly1->next; 
	nodeptr p2 = poly2->next;
	while(p1!=NULL){
		p2=poly2->next;
		while(p2!=NULL){
			addTerm(result,p1->coef*p2->coef,p1->exp+p2->exp);
			p2 = p2->next;	
		}
		p1 = p1->next;
	}
	return result;
}

// return a new polynomial that represents the derivative of p1
Polynomial derivative(const Polynomial poly){
	Polynomial result = newPoly();
	nodeptr p = poly->next;
	int coeff=0;
	int exp = 0; 
	while(p!=NULL){
		coeff = p->coef*p->exp; 
		exp = p->exp -1; 
		addTerm(result,coeff,exp);
		p = p->next;
	}
	return result;
}

// compute the value of the polynomial given a value for x
int evaluate(const Polynomial poly,int x){
	nodeptr p = poly->next;
	int ans=0;
	while(p!=NULL){
		ans += (int)pow(x,p->exp) * p->coef;
		p=p->next;
	}
	return ans; 
}

// return 1 if the value of p is constant, 0 otherwise
int isConstant(const Polynomial poly){
	nodeptr p = poly->next;
	int flag=1;
	while(p!=NULL){
		if(p->exp!=0){
			flag=0;
			break;
		}
		p = p->next;
	}
	return flag;
}

// return 1 if the value of p is zero (0), 0 otherwise
int isZero(const Polynomial poly){
	nodeptr p = poly->next;
	int flag=1; 
	while(p!=NULL){
		if(p->coef!=0){
			flag=0;
			break; 
		}
		p = p->next;
	}
	return flag;	
}

