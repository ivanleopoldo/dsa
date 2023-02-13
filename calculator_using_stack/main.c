#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct node {
    float data;
    struct node *next;
} Stack;

Stack *top = NULL;
char postfix[MAX] = "";

void push(float);
float pop();
void display();
float evaluate(char*);

void main(){
    char equation[MAX];
    float result;
    printf("Input Equation: ");
    scanf("%s", equation);

    result = evaluate(equation);

    printf("\n");
    printf("result:\n%s = %f", equation, result);
}

float evaluate(char *equation){
    int i=0;
    char temp;

    for(;i<strlen(equation);i++){
        if(isdigit(equation[i])){
            strncat(postfix, &equation[i], 1);
        } else if(equation[i] == ')'){
            if(top!=NULL){
                temp = (int)pop();
                strncat(postfix, &temp, 1);
            }
        } else if(equation[i] != '(') {
            push(equation[i]);
        }
    }

    while(top!=NULL){
        temp = pop();
        strncat(postfix, &temp, 1);
    }

    int k=0;
    float A, B;
    for(; postfix[k]!='\0'; k++){
        if(isdigit(postfix[k])){
            char temp = postfix[k];
            push(atoi(&temp));
        } else {
            A = pop();
            B = pop();
            switch(postfix[k]){
                case '+':{
                    push(A+B);
                    break;
                }
                case '-':{
                    push(B-A);
                    break;
                }
                case '*':{
                    push(A*B);
                    break;
                }
                case '/':{
                    push(B/A);
                    break;
                }
            }
        }
    }
    return pop();
}

void push(float data){
    if(top==NULL){
        top = (Stack*)malloc(sizeof(Stack*));
        top->data = data;
        top->next = NULL;
    } else {
        Stack *temp = (Stack*)malloc(sizeof(Stack*));
        temp->data = data;
        temp->next = top;
        top = temp;
    }
}

float pop(){
    if(top==NULL){
        printf("Empty Stack");
    } else {
        Stack *temp=top;
        float data = top->data;
        temp=temp->next;
        free(top);
        top=temp;
        return data;
    }
}

void display(){
    Stack *trav = top;
    for(; trav!=NULL; trav=trav->next){
        printf("%f \n", trav->data);
    }
}