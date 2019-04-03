#include<stdio.h>
#include<stdlib.h>
#define N 500

int Q[N];
int last=0;

int enqueu(int item){
	if(last=N){
		printf("Queue is full\n");
		return -1;
	}
	else{
		Q[last]=item;
		last++;
		return 0;
	}
}

int dequeu(){
	int item,i;
	if(last==0){
		printf("Queue is empty\n");
		return -1;
	}
	else{
		item=Q[0];
		for(i=1;i<last;i++)
		Q[i-1]=Q[i];
		last--;
		return item;
	}
}

void reset(){
	last=0;
}

int main(){
	int c;
	scanf("%d",&c);
	enqueu(c);
	printf("%c",dequeu());
	printf("\n");
	return 0;
}
