#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list{
	int info;
	char message;
	struct linked_list *next;
}SIMPLE_LIST;
SIMPLE_LIST *first=NULL;
SIMPLE_LIST *last=NULL;

void insert(SIMPLE_LIST *p){
	if(first!=NULL){
		last->next=p;
		p->next=NULL;
		last=p;
	}
	else {
	first=p;
	last=p;
	p->next=NULL;
}
}

int display(){
	SIMPLE_LIST *p;
	p=first;
	if(p==NULL){
		printf("List is empty\n");
		return -1;
	}
	while(p!=NULL){
		printf("%d %s\n",p->info,p->message);
		p=p->next;
	}
	return 0;
}

SIMPLE_LIST *search(int key){
	SIMPLE_LIST *p;
	p=first;
	while(p){
		if(p->info==key)
		printf("Key found\n");
		p=p->next;
	}
	return NULL;
}

SIMPLE_LIST *delet(int key){
	SIMPLE_LIST *p,*previous;
	p=first;
	previous=NULL;
	while(p){
		if(key==p->info)
		break;
		previous=p;
		p=p->next;
	}
	if(p!=NULL){
		if(previous==NULL){
			if(first==last){
				first=NULL;
				last==NULL;
			}
			else{
			 first=first->next;
		    	}
			}
		
		    else {
		    	previous->next=p->next;
		    	if(previous->next==NULL){
		    		last=previous;
				}
			}
			free(p);
			return(p);
	}
		else return NULL;
}

int main() {
	int x;	
	for(int i=0;i<5;i++){
		SIMPLE_LIST *item=(SIMPLE_LIST*) malloc (sizeof(SIMPLE_LIST));
		scanf("%d%c",&item->info,&item->message);
		insert(item);
	}
	display();	
	printf("Write a number to search");
	scanf("%d",&x);
	search(x);
	delet(4);
	display();
	return 0;
}
