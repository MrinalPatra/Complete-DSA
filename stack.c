#include<stdio.h>
#include<stdlib.h>
struct stack{
	int size;
	int top;
	int *array;
};
struct stack *createstack(int size){
	struct stack *Stack=(struct stack *)malloc(sizeof(struct stack));
	Stack->size=size;
	Stack->top=-1;
	Stack->array=(int *)malloc(size*sizeof(int));
	return Stack;
}
int Is_Empty(struct stack *a){
	if(a->top==-1){
  		return 0;
	}
	else{
		return 1;
	}
}
int Is_Full(struct stack *a){
	int s,r;
	s=a->size;
	r=a->top;
	if(s==(r+1)){
		return 0;
	}
	else{
		return 1;
	}
}
void push(struct stack *ab){
	int i;
	i=Is_Full(ab);
	if(i==0){
   	printf("Stack is full\n");
	}
	else{
  		int s;
		printf("Enter data you want to push into stack:");
		scanf("%d",&s);
		ab->array[++ab->top]=s;
	}
}
void pop(struct stack *s){
	int i;
	i=Is_Empty(s);
	if(i==0){
		printf("Stack is empty\n");
	}
	else{
		printf("%d poped out of stack\n",s->array[s->top]);
		s->top--;
	}
}
void peek(struct stack *s){
	printf("Element at top: %d\n",s->array[s->top]);
}
void show(struct stack *s){
	int i;
	i=Is_Empty(s);
	if(i==0){
   	printf("Stack is Empty\n");
	}
	else{
		int d=s->top;
		while(d!=-1){
			printf("%d ",s->array[d]);
			d--;
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
	int a,n;
	printf("Enter size of stack:");
	scanf("%d",&n);
	struct stack *stack1=createstack(n);
	printf("Press 1. to push an element\nPress 2. to pop an element\nPress 3. to peek\nPress 4. to show stack\n");
	while(getans()){
		printf("Enter your choice:");
		scanf("%d",&a);
		if(a==1){
			push(stack1);
		}
		else if(a==2){
			pop(stack1);
		}
		else if(a==3){
			peek(stack1);
		}
		else if(a==4){
			show(stack1);
		}
		else{
			printf("Invalid choice\n");
		}
	}
}

