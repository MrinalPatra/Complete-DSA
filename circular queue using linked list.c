#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *create(){
	struct node *queue=(struct node *)malloc(sizeof(struct node));
	queue->next=0;
	return queue;
}
int Is_Full(int c,int size){
	if(c==size-1){
		return 0;
	}
	else{
		return 1;
	}
}
int Is_Empty(int c){
	if(c==-1){
		return 0;
	}
	else{
		return 1;
	}
}
struct node *Enqueue(struct node *a,int size,int c){
	if(c==-1){
		struct node *s=create();
		int b;
		printf("Enter data:");
		scanf("%d",&b);
		s->data=b;
		return s;
	 }
	else{
		struct node *s=create();
		int b;
		printf("Enter data:");
		scanf("%d",&b);
		a->next=s;
		s->data=b;
		return s;
	}
}
struct node *Dequeue(struct node *a,struct node *b,int c,int size){
	if(a->data==b->data){
		struct node *temp=create();
		printf("Dequeued element is %d\n",b->data);
		free(b);
		temp->data=0;
		return temp;
	}
	else{
		printf("Dequeued element is %d\n",b->data);
		struct node *temp=b->next;
		a->next=temp;
		free(b);
		return temp;
	}
}
void peek(struct node *b){
	printf("Element at top is %d\n",b->data);
}
void display(struct node *b,int c){
	int i;
	if((i=Is_Empty(c))==0){
		printf("Queue is Empty\n");
	}
	else{
		struct node *temp=b;
		while(b->next!=temp){
			printf("%d ",b->data);
			b=b->next;
		}
		printf("%d ",b->data);
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
	int size,c,i,a;
	c=-1;
	printf("Enter size of queue:");
	scanf("%d",&size);
	struct node *head,*tail;
	printf("Press 1. to Enqueue an element\nPress 2. to Dequeue an element\nPress 3. to peek\nPress 4. to display queue\n");
	while(getans()){
		printf("Enter your choice:");
		scanf("%d",&a);
		if(a==1){
			if((i=Is_Full(c,size))==0){
				printf("Queue is Full\n");
			}
			else if(c==-1){
				head=tail=Enqueue(tail,size,c);
				c+=1;
				tail->next=head;
			}
			else{
				tail=Enqueue(tail,size,c);
				c+=1;
				tail->next=head;
			}
		}
		else if(a==2){
			if((i=Is_Empty(c))==0){
				printf("Queue is Empty\n");
			}
			else if(head->data==tail->data){
				tail=head=Dequeue(tail,head,c,size);
				c=-1;
			}
			else{
				head=Dequeue(tail,head,c,size);
				c-=1;
			}
		}
		else if(a==3){
			if((i=Is_Empty(c))==0){
				printf("Queue is Empty\n");
			}
			else{
				peek(head);
			}
		}
		else if(a==4){
			display(head,c);
		}
		else{
			printf("Invalid choice\n");
		}
	}

}

