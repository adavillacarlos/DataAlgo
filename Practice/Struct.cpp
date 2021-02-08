#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account{
	char name[20]; 
	int accountId; 
	double balance; 
};

typedef struct account Account;
//void display(Account act); //to make it faster make it to pointer

//input parameter - there is no change in the act
//put const so that it wouldn't be change. 
void display(const Account *act);

//output parameter - there is a change in the act
void initialize(Account *act,const char *name, double balance);

//input&output parameters - since you need to view it and you have to change it. 
int withdraw(Account *act, double amount); 

int main(){
	//Account becomes a data type much better than struct account
	//Accound act1 is located in the Stack. 
	Account act1,act2,act3; 
	//Allocate another memory for the account, only copies the act1 to acc. 
		//display(act1); 
	initialize(&act1,"ada",100.00); 
	initialize(&act2,"pauline",200.00); 
	initialize(&act3,"ronerr",300.00); 

	display(&act1); 
	display(&act2); 		
	display(&act3); 

	return 0; 
}

void initialize(Account *act,const char *name, double balance){
	//is not like local, since it retains it value. 
	static int accountId = 1; 
	strcpy(act->name,name);
	act->balance = balance;
	act->accountId = accountId++;  
	
}


void display(const Account *act){
	printf("\nId: %d",act->accountId); 
	printf("\nName: %s",act->name); 
	printf("\nBalance: %lf",act->balance);
}

int withdraw(Account *act, double amount){
	
}
