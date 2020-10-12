#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

struct node{
	char from[LEN+1];
	char to[LEN+1];
	int value;
	char item[LEN];
	struct node *next;
};

struct node *head = NULL;

//insert link at the first location
void insertFirst(struct node **head,char* tx, char* rx, int v, char* name) {
   	struct node *link = (struct node*) malloc(sizeof(struct node));

	strncpy(link->from, tx, LEN);
	strncpy(link->to, rx, LEN);
	link->value = v;
	strncpy(link->item, name, LEN);
	
	printf("#### Debug: Add to Linked list >>>>");
    printf("(%s, %s, %d, %s)\n\n",link->from,link->to,link->value,link->item);

   	link->next = *head;
   	*head = link;
}

void printList(struct node *head) {
   	struct node *ptr = head;

   	while(ptr) {
      	printf("(%s, %s, %d, %s)\n",ptr->from, ptr->to, ptr->value, ptr->item);
    	ptr = ptr->next;
   	}
}
int printLoan(char* name){
	int found = 0;

	struct node *newList = NULL;
	struct node *ptr = head;
	
	// temp node, will be freed after exit this func.
   	struct node *link = (struct node*) malloc(sizeof(struct node));
	
	while(ptr) {
		if(strcmp(ptr->from,name)==0){
			found = 1;
			insertFirst(&newList,ptr->from,ptr->to,ptr->value,ptr->item);
		}
		else if(strcmp(ptr->to,name)==0){	// swap to and from, and add '-' to value
			insertFirst(&newList,ptr->to,ptr->from,-1*ptr->value,ptr->item);
			found = 1;
		}
		ptr = ptr->next;
	}
	if(found==0){
		printf("Loan not found: %s\n",name);
		return 1;
	}
	else{
		printList(newList);
		return 0;
	}
} 

void freeList() {
  	struct node* ptr = head;
  	struct node* tmp = NULL;
  	while(ptr) {
  	  	tmp = ptr->next;
  	  	free(ptr);
    	ptr = tmp;
	}
}


int input(){
	printf("----------------  input data  ---------------------\n");
	printf("John needs to give Mary 10 dollars for coffee \n");	
	printf("Type in: John Mary 10 coffee \n");	
	printf("->");	
	char tx[LEN], rx[LEN], name[LEN];
	int dollars;

	scanf("%20s",tx);
	scanf("%20s",rx);
	scanf("%d",&dollars);
	scanf("%20s",name);

	insertFirst(&head,tx,rx,dollars,name);
	printf("----------------  data added  ----------------------\n");

	return 0;
}
int show(){
	char str[LEN];
	printList(head);
	printf("###################################\n");
  	printf("Whos' loan you want to check? ");
	scanf("%s", str);
	printLoan(str);
	return 0;
}
int menu(){
	printf("================  prompt  ==========================\n");
	printf("What do you want to do?");
	printf("\n");
	printf("input: i\n");
	printf("quit: q\n");
	printf("show: s\n");

	char str[20];
	printf("-> ");
	scanf(" %s",str);

	if (strcmp(str,"i") == 0){
		input();
	}
	else if (strcmp(str,"q") == 0){
		freeList();
		exit(0);
	}
	else if (strcmp(str,"s") == 0){
		printf("show()\n");
		printList(head);
		printf("###########################\n");
		show();
	}
	else {
		printf("Invalid input!\n");
	}
	return 0;
}

int main() {
	printf("================  Go Dutch ========================\n");
	printf("This program is designed for splitting bills\n");
	printf("author: mega-pan\n");

	while(1){
		menu();
	}
	return 0;

}
