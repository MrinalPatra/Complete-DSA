#include<stdio.h>
#include<stdlib.h>
struct lls{
	int data;
	struct lls *node;
};
struct lls *create(){
	struct lls *a=(struct lls *)malloc(sizeof(struct lls));
 	a->node=0;
	return a;
}
struct lls *push(struct lls *a,int top){
	struct lls *s=create();
	printf("Enter data:");
	scanf("%d",&s->data);
	if(top==-1){
		s->node=0;
 	}
 	else{
		s->node=a;
	}
	return s;
}
struct lls *pop(struct lls *a,int top){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		struct lls *temp=a;
		a=a->node;
		printf("%d poped out of stack\n",temp->data);
		free(temp);
		return a;
	}
}
struct lls *peek(struct lls *a,int top){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		printf("Element at top is %d",a->data);
	}
}
struct lls *show(struct lls *a,int top){
	if(top==-1){
		printf("Stack is empty\n");
	}
	else{
		while(a!=0){
			printf("%d ",a->data);
			a=a->node;
		}
		printf("\n");
	}
}
int getans(){
	int d;
	printf("Press '0' to exit and '1' to continue:");
	scanf("%d",&d);
	return d;
}
int main(){
	int a;
	int top=-1;
	struct lls *k;
	printf("Press 1. to push an element\nPress 2. to pop an element\nPress 3. to peek\nPress 4. to show stack\n");
	while(getans()){
		printf("Enter your choice:");
		scanf("%d",&a);
		if(a==1){
			k=push(k,top);
			top++;
		}
		else if(a==2){
			k=pop(k,top);
		}
		else if(a==3){
			peek(k,top);
		}
		else if(a==4){
			show(k,top);
		}
		else{
			printf("Invalid choice\n");
		}
	}
}
