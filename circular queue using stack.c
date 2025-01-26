#include<stdio.h>
#include<stdlib.h>
struct node{
	int front;
	int rear;
	int *queue;
	int size;
};
struct node *create(int size){
	struct node *a=(struct node *)malloc(sizeof(struct node));
	a->size=size;
	a->front=a->rear=-1;
	a->queue=(int *)malloc(size*sizeof(int));
	return a;
}
int Is_Full(struct node *a){
	if(((a->rear+1)%a->size)==a->front){
		return 0;
	}
	else{
		return 1;
	}
}
int Is_Empty(struct node *a){
	if(a->front==-1 & a->rear==-1){
		return 0;
	}
	else{
		return 1;
	}
}
void Enqueue(struct node *a){
	int i;
	if((i=Is_Full(a))==0){
		printf("Queue is Full\n");
	}
	else if(a->front==-1 & a->rear==-1){
		int b;
		printf("Enter data:");
		scanf("%d",&b);
		a->rear++;
		a->front++;
		a->queue[a->front]=a->queue[a->rear]=b;
	}
	else{
		int b;
		printf("Enter data:");
		scanf("%d",&b);
		a->rear=(a->rear+1)%a->size;
		a->queue[a->rear]=b;
		
	}
}
void Dequeue(struct node *a){
	int i;
	if((i=Is_Empty(a))==0){
		printf("Queue is Empty\n");
	}
	else if(a->rear==a->front){
		printf("Dequeued element is %d\n",a->queue[a->front]);
		a->rear=a->front=-1;
	}
	else{
		printf("Dequeued element is %d\n",a->queue[a->front]);
		a->front=(a->front+1)%a->size;
	}
}
void peek(struct node *a){
	int i;
	if((i=Is_Empty(a))==0){
		printf("Queue is Empty\n");
	}
	else{
		printf("Element at top is %d\n",a->queue[a->front]);
	}
}
void display(struct node *a){
	int i;
	if((i=Is_Empty(a))==0){
		printf("Queue is Empty\n");
	}
	else{
		int i=a->front;
		while(i!=a->rear){
			printf("%d ",a->queue[i]);
			i=(i+1)%a->size;
		}
		printf("%d ",a->queue[i]);
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
	int n,a;
	printf("Enter size of queue:");
	scanf("%d",&n);
	struct node *s=create(n);
	printf("Press 1. to Enqueue an element\nPress 2. to Dequeue an element\nPress 3. to peek\nPress 4. to display queue\n");
	while(getans()){
		printf("Enter your choice:");
		scanf("%d",&a);
		if(a==1){
			Enqueue(s);
		}
		else if(a==2){
			Dequeue(s);
		}
		else if(a==3){
			peek(s);
		}
		else if(a==4){
			display(s);
		}
		else{
			printf("Invalid choice\n");
		}
	}

}

