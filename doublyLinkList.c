#include<stdio.h>
#include<stdlib.h>
typedef struct doubly_list{
	int info;
	char message[50];
	struct doubly_list *next;
	struct doubly_list *previous;
}DLIST;
DLIST *first=NULL;
DLIST *last=NULL;

void insert(DLIST *p){
	if(first==NULL){
		first=p;
		last=p;
		first->previous=NULL;
		p->next=NULL;
	}
	else{
		last->next=p;
		p->previous=last;
		last=p;
		p->next=NULL;
	}
}

void display(){
	DLIST *p;
	p=last;
	while(p){
		printf("%d\n",p->info);
		p=p->previous;
	}
}

DLIST *search(int key){
	DLIST *p;
	p=first;
	while(p){
		if(key==p->info)
		return p;
		p=p->next;
}
	 return NULL;
}

DLIST *delet(int key){
	DLIST *p;
	p=search(key);
	if(p==NULL){
	printf("The element is not on the list");
	return NULL;
	}
	if(p==first){
		if(first==last){
			first=NULL;
			last=NULL;
		}
		else{
			first=p->next;
			first->previous=NULL;
		}
	}
	else{
		if(p==last){
			last=p->previous;
			last->next=NULL;
		}
		else{
			p->previous->next=p->next;
			p->next->previous=p->previous;
		}
	}
	free(p);
	return p;
}

int store(){
	FILE *fp;
	DLIST *p;
	if((fp=fopen("list.txt","w"))==NULL){
		printf("File cannot be opened,disk is full\n");
		return -1;
	}
	p=first;
	while(p){
		fwrite(p,sizeof(DLIST)-2*sizeof(p),1,fp);
		p=p->next;
	}
	printf("List was stored\n");
	fclose(fp);
	return 0;
	}

int main() {
int x;	
	for(int i=0;i<5;i++){
		DLIST *item=(DLIST*) malloc (sizeof(DLIST));
		scanf("%d %s",&item->info,&item->message);
		insert(item);
	}
	display();	
	printf("Write a number to search");
	scanf("%d",&x);
	search(x);
	delet(5);
	display();
	return 0;
}
