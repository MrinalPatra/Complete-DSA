#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *createnode(){
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->next=0;
	return newnode;
}
struct node *IAB(struct node *head,int c){
	struct node *a=(struct node *)malloc(sizeof(struct node) );
	struct node *node;
	node=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you want to insert at beginning:");
	scanf("%d",&node->data);
	if(c==0){
		head=node;
		head->next=0;
	}
	else{
		node->next=head;
		head=node;
	}
	c++;
	a->data=c;
	a->next=head;
	return a;
}
struct node *IAE(struct node *head,int c){
	struct node *a=(struct node *)malloc(sizeof(struct node) );
	struct node *node;
	node=(struct node *)malloc(sizeof(struct node));
	printf("Enter data you want to insert at last:");
	scanf("%d",&node->data);
	if(c==0){
		head=node;
		head->next=0;
		a->data=c++;
		a->next=head;
		return a;
  	}
	else{
		while(head->next!=0){
			head=head->next;
		}
		head->next=node;
		node->next=0;
		a->data=c++;
		a->next=0;
		return a;
	}
}
struct node *IAP(struct node *head,int c){
	int s,i;
	struct node *node,*temp;
	node=(struct node *)malloc(sizeof(struct node));
	struct node *a=(struct node *)malloc(sizeof(struct node));
	printf("Enter position after which you want to insert a node:");
	scanf("%d",&s);
	if(c==0){
		head=node;
		head->next=0;
		c+=1;
		a->data=c;
		a->next=head;
		return a;
	}
	else{
		if(s==1){
			a=IAB(head,c);
			return a;
		}
		else if (s==c){
			a=IAE(head,c);
			return a;
		}
		else if (s<1 || s>c){
			a->next=0;
			a->data=0;
			return a;
		}
		else{
			i=1;
			temp=head;
			while(i!=s){
				temp=temp->next;
				i+=1;
 			}
			printf("Enter data you want to insert after node %d:",s);
			scanf("%d",&node->data);
			node->next=temp->next;
 			temp->next=node;
 			c+=1;
	 		a->data=c;
	 		a->next=0;
 			return a;
		}
	}
}
int putdata(struct node *data,int c){
	printf("Enter data");
	scanf("%d",&data->data);
	data->next=0;
	c++;
	return c;
}
int getans(){
	int d;
	printf("Press '0' to exit and '1' to continue:");
	scanf("%d",&d);
	return d;
}
int end(){
	int b;
	printf("1.Choose again\n0.Exit\n");
	scanf("%d",&b);
	return b;
}
void showdata(struct node *head,int c){
	if (c==0){
		printf("List is empty\n");
	}
	else{
		while(head!=0){
			printf("%d ",head->data);
			head=head->next;
		}
		printf("\n");
	}
}
struct node *DFB(struct node *head,int c){
	if (c==0){
		printf("List id empty\n");
	}
	else{
		struct node *a=(struct node *)malloc(sizeof(struct node));
		struct node *temp;
		temp=head;
		head=head->next;
		free(temp);
		c-=1;
		a->next=head;
		a->data=c;
		return a;
	}
}
struct node *DFE(struct node *head,int c){
	if (c==0){
		printf("List id empty\n");
	}
	else if(c==1){
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		free(head);
		c=0;
		a->data=c;
		a->next=0;
		return a;
	}
	else{
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		struct node *temp;
		if(head->next!=0){
			temp=head;
			head=head->next;
		}
		temp->next=0;
		free(head);
		a->data=c--;
		a->next=0;
		return a;
	}
}
struct node *DFP(struct node *head,int c){
	if (c==0){
		printf("list id empty");
	}
	else{
		int s,i;
		i=1;
		struct node *next1,*temp;
		printf("Enter position of node you want to delete:");
		scanf("%d",&s);
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		if(s==1){
			a=DFB(head,c);
			return a;
		}
		else if (s==c){
			a=DFE(head,c);
			return a;
		}
		else if (s<1 || s>c){
			a->data=0;
			a->next=0;
			return a;

		}
		else{
			c++;
			if(s<c){
				temp=head;
				while (i<s-1){
					temp=temp->next;
					i++;
				}
				next1=temp->next;
				temp->next=next1->next;
				free(next1);
			}
			a->data=c--;
			a->next=0;
			return a;
		}
	}
}
struct node *reverse(struct node *head){
	struct node *currentnode,*prevnode,*nextnode;
	prevnode=0;
	currentnode=nextnode=head;
	while(nextnode!=0){
		nextnode=nextnode->next;
		currentnode->next=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	head=prevnode;
	return head;
}
int main()
{
	int a,b;
	struct node *g=(struct node *)malloc(sizeof(struct node) );
	b=0;
	while(end()){
		printf("Enter according to your choice:\nPress 1.To create a new list\nPress 2.To print the list\nPress 3.To insert at beginning of list\nPress 4.To insert at end of list\nPress 5.To insert at a position of list\nPress 6.To delete a node from beginning of list\nPress 7.To delete a node from last of list\nPress 8.To delete a node from given position of list\nPress 9.To reverse a list\n");
		printf("Enter your choice:");
		scanf("%d",&a);
		int c;
		struct node *head,*temp;
		if (a==1){
			head=createnode();
			c=putdata(head,c);
			temp=head;
			while(getans()){
				temp->next=createnode();
				temp=temp->next;
				c=putdata(temp,c);
			}
		}
		else if(a==2){
			showdata(head,c);
		}
		else if(a==3){
			g=IAB(head,c);
			head=g->next;
			c=g->data;
		}
		else if(a==4){
			g=IAE(head,c);
			if(g->next!=0){
				head=g->next;
				c=g->data;
			}
			else{
				c=g->data;
			}
		}
		else if(a==5){
			struct node *a=IAP(head,c);
			if (a->data==1){
				head=a->next;
			}
			else if (a->next==0 & a->data==0){
				printf("Invalid position\n");
			}
			else if (a->next==0 & a->data!=0){
				c=a->data;
			}
			else{
				head=a->next;
				c=a->data;
			}
		}
		else if(a==6){
			struct node *a=DFB(head,c);
			head=a->next;
			c=a->data;
		}
		else if(a==7){
			struct node *a=DFE(head,c);
			if(a->data==0){
				c=0;
			}
			else{
				c=a->data;
			}
		}
		else if(a==8){
			struct node *a=DFP(head,c);
			if (a->next==0 & a->data==0){
				printf("Invalid position\n");
			}
			else if (a->next==0 & a->data!=0){
				c=a->data;
			}
			else{
				head=a->next;
				c=a->data;
			}
		}
		else if(a=9){
			head=reverse(head);
		}
		else{
			printf("Invalid chioce\n");
		}
	}
}
