#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char *from;
	char *to;
	int value;
	char *item;
	struct node *next;
};

struct node *head = NULL;

//insert link at the first location
void insertFirst(char* tx, char* rx, int v, char* name) {
   	struct node *link = (struct node*) malloc(sizeof(struct node));

	link->from = tx;
	link->to = rx;
	link->value = v;
	link->item = name; 
	
	printf("#### Debug: Add to Linked list >>>>");
    printf("(%s, %s, %d, %s)\n\n",link->from,link->to,link->value,link->item);

   	link->next = head;
   	head = link;
}

void printList() {
   struct node *ptr = head;
	
   	while(ptr) {
      	printf("(%s, %s, %d, %s)\n",ptr->from, ptr->to, ptr->value, ptr->item);
    	ptr = ptr->next;
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
	char tx[20], rx[20], name[20];
	int dollars;

	scanf("%20s",tx);
	scanf("%20s",rx);
	scanf("%d",&dollars);
	scanf("%20s",name);

	insertFirst(tx,rx,dollars,name);
	printf("----------------  data added  ----------------------\n");

	return 0;
}
/*int show(){
	return 0;
}*/
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
		printList();
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
