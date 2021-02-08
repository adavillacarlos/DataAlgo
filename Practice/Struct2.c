#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account{
	char name[20]; 
	int accountId; 
	double balance; 
};
//A pointer to a structure
typedef struct account *Account;

//void display(Account act); //to make it faster make it to pointer

//input parameter - there is no change in the act
//put const so that it wouldn't be change. 
void display(const Account act);

//output parameter - there is a change in the act
Account newAccount(const char *name, double balance);

//input&output parameters - since you need to view it and you have to change it. 
int withdraw(Account act, double amount); 

int main(){
	//act1,act2,act3 are already pointers since they are holding the address of a structure.
	//are like references in the java. 
	Account act1,act2,act3; 
	act1 = newAccount("ada",100.00); 
	act2 = newAccount("pauline",200.00); 
	act3 = newAccount("ronerr",300.00); 

	display(act1); 
	display(act2); 		
	display(act3); 
	
	free(act1);
	free(act2);
	free(act3);

	return 0; 
}

Account newAccount(const char *name, double balance){
	
	Account act = (Account)malloc(sizeof(struct account));
	//is not like local, since it retains it value. 
	static int accountId = 1; 
	strcpy(act->name,name);
	act->balance = balance;
	act->accountId = accountId++;  
	return act;
}


void display(const Account act){
	printf("\nId: %d",act->accountId); 
	printf("\nName: %s",act->name); 
	printf("\nBalance: %lf",act->balance);
}

int withdraw(Account act, double amount){
	
}
