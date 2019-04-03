#include<stdio.h>
#include<stdlib.h>
typedef struct s{
	int item;
	struct s *next;
}STACK;

STACK *sp=NULL;

int push(int item){
	STACK *p;
	p=(STACK *)malloc(sizeof(STACK));
	if(p==NULL){
		printf("Error,not enough memory");
		return -1;
	}
	else{
    p->item=item;
	p->next=sp;
	sp=p;
	return 0;
    }
}

int pop(){
	STACK *p;
	int i;
	if(sp==NULL){
		printf("Stack is empty\n");
		return -1;
	}
	else{
		p=sp;
		i=sp->item;
		sp=sp->next;
		free(p);
		return i;
	}
}

void reset(){
	STACK *p;
	while(sp!=NULL){
		p=sp;
		sp=sp->next;
		free(p);
	}
}

STACK *top(){
	return sp;
}

int size(){
	STACK *p;
	int i=0;
	p=sp;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

STACK *isEmpty(){
	return sp;
}

int main(){
	char c;
	while((c=getchar())!='\n')
	push(c);
	while(sp>0)
	printf("%c",pop());
	printf("\n");
	return 0;
}
