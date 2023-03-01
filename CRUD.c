// save as a header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char data[100];
	struct node *link;
} *LIST;

void insert(LIST *L, char *str);
void deleteThis(LIST *L, char *str);
void edit(LIST *L, char *str, char *newstr);
void show(LIST L);

void main(){
	LIST HEAD = NULL;
	
	insert(&HEAD, "aa");
//	show(HEAD);
	insert(&HEAD, "zz");
//	show(HEAD);
	insert(&HEAD, "bb");
//	show(HEAD);
	deleteThis(&HEAD, "aa");
//	show(HEAD);
}

void insert(LIST *L, char *str){	
	LIST *trav;
	for(trav = L;*trav!=NULL && strcmp((*trav)->data, str) < 0; trav=&(*trav)->link ){}
	LIST newNode = (LIST)malloc(sizeof(struct node));
	if(newNode!=NULL){
		strcpy(newNode->data, str);
		newNode->link = *trav;
		*trav = newNode;
	}
}

void show(LIST L){
	LIST trav = L;
	if(L!=NULL){
		for(;trav!=NULL; trav=trav->link){
			printf("%s -> ", trav->data);
		}
		printf("NULL");	
	} else {
		printf("ERROR: list is empty");
	}
	printf("\n");
}

void deleteThis(LIST *L, char *str){
	/* 
		bugs:
			while loop condition
			delinking and relinking of link
	*/
	LIST *trav = L, *temp;
	
	while(trav != NULL && strcmp((*trav)->data, str)!=0){
		temp = trav;
		trav = &(*trav)->link;
	}
//	printf("%s %s", (*temp)->data, (*trav)->data);
//	(*temp)->link = (*trav)->link;
//	free(*trav);
}

void edit(LIST *L, char *str, char *newstr){
	
}
