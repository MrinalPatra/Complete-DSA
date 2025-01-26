 #include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *createnode(){
   	struct node *p;
   	p=(struct node *)malloc(sizeof(struct node));
   	return p;
}
void putdata(struct node *p)
   {
   	int data;
   	printf("Enter data\n");
   	scanf("%d",&data);
   	p->data=data;
   	p->next=0;
   }
int getans1()
   {
   	int n;
   	printf("Enter 0 to stop and 1 to continue entering data\n");
   	scanf("%d",&n);
   	return n;

   }
int getans2()
   {
   	int n;
   	printf("Enter 0 to stop and 1 to perform any other operation\n");
   	scanf("%d",&n);
   	return n;

   }
void showdata1(struct node *head,int len )
{
	if(len==0){
		printf("List is empty\n");
	}
	else{
		struct node *p=head->next;
		printf("list using next pointer:\n");
		printf("%d ",head->data);
		while(p!=head){
		   printf("%d  ",p->data);
		   p=p->next;
		}
		printf("%d",p->data);
		printf("\n");
	}
}
void showdata2(struct node *tail,int len )
{
	if(len==0){
		printf("List is empty\n");
	}
	else{
	struct node *p=tail;
		printf("list using rev pointer:");
		while(p->prev!=tail){
		   printf("%d  ",p->data);
		   p=p->prev;
		}
  		printf("%d ",p->data);
  		printf("%d",p->prev->data);
		printf("\n");
	}
}
struct node *IAB(struct node *head,struct node *tail,int len){
	struct node *node1=createnode();
	putdata(node1);
	struct node *a=(struct node *)malloc(sizeof(struct node) );
	if (len==0){
		node1->next=node1;
		node1->prev=node1;
	}
	else{
		node1->next=head;
		node1->prev=tail;
		head->prev=node1;
		tail->next=node1;
	}
	len+=1;
	a->prev=node1;
	a->data=len;
	a->next=0;
	return a;
}
struct node *IAE(struct node *head,struct node *tail,int len){
	struct node *a=(struct node *)malloc(sizeof(struct node) );
	struct node *node1=createnode();
	putdata(node1);
	if (len==0){
		node1->next=node1;
		node1->prev=node1;
	}
	else{
		tail->next=node1;
		node1->prev=tail;
		head->prev=node1;
		node1->next=head;
	}
	len+=1;
	a->prev=0;
	a->data=len;
	a->next=node1;
	return a;
}
struct node *IAP(struct node *head,struct node *tail,int len){
	if (len==0){
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		struct node *node1=createnode();
		putdata(node1);
		node1->next=node1;
		node1->prev=node1;
		len+=1;
		a->prev=0;
		a->data=len;
		a->next=node1;
		return a;
	}
	else{
		int s,c;
		c=1;
		printf("Enter the node after which you want to insert:");
		scanf("%d",&s);
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		if(s==1){
			a=IAB(head,tail,len);
			return a;
		}
		else if (s==len){
			a=IAE(head,tail,len);
			return a;
		}
		else if (s<1 || s>len){
			a->data=0;
  			a->next=0;
  			a->prev=0;
			return a;
		}
		else{
			struct node *node1=head;
			struct node *temp;
			while(c!=s){
				head=head->next;
				c++;
			}
			temp=createnode();
			putdata(temp);
			temp->prev=head;
			temp->next=head->next;
			head->next=temp;
			temp->next->prev=temp;
  			len+=1;
			a->data=len;
  			a->next=0;
  			a->prev=0;
			return a;
		}
	}
}
struct node *DFB(struct node *head,struct node *tail,int len){
	if(len==1){
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		free(head);
		len-=1;
		a->data=0;
		a->next=0;
		a->prev=0;
		return a;
	}
	else{
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		struct node *temp=head->next;
		temp->prev=tail;
		tail->next=temp;
		free(head);
		len-=1;
		a->data=len;
  		a->next=0;
  		a->prev=temp;
		return a;
	}
}
struct node *DFE(struct node *tail,struct node *head,int len){
	if(len==1){
		struct node *a=(struct node *)malloc(sizeof(struct node) );
		free(tail);
		len-=1;
		a->data=0;
		a->next=0;
		a->prev=0;
		return a;
	}
	else{
		struct node *a=(struct node *)malloc(sizeof(struct node));
		struct node *temp=tail->prev;
		temp->next=head;
		head->prev=temp;
		free(tail);
		len-=1;
		a->data=len;
  		a->next=temp;
  		a->prev=0;
		return a;
	}
}
struct node *DFP(struct node *head,struct node *tail,int len){
	if(len==1){
		struct node *a;
		free(head);
		len-=1;
		a->data=0;
		a->next=0;
		a->prev=0;
		return a;
	}
	else{
		int c,s;
		printf("Enter the position at which you want to delete the element:");
		scanf("%d",&s);
		struct node *a=(struct node*)malloc(sizeof(struct node) );
		if(s==1){
			a=DFB(head,tail,len);
			return a;
		}
		else if (s==len){
			a=DFE(tail,head,len);
			return a;
		}
		else if (s<1 || s>len){
			a->data=0;
			a->next=0;
			a->prev=0;
			return a;
		}
		else{
			c=1;
			while(c!=s){
				head=head->next;
				c++;
			}
			head->prev->next=head->next;
			head->next->prev=head->prev;
			free(head);
			len-=1;
			a->data=len;
			a->next=0;
			a->prev=0;
			return a;
		}
	}
}
int main()
{
	struct node *head,*node,*tail;
	struct node *a;
	int n,len;
	printf("Enter according to your choice:\nPress 1.To create a new list\nPress 2.To print the list using next pointer\nPress 3.To print the list using rev pointer\nPress 4.To insert at beginning of list\nPress 5.To insert at end of list\nPress 6.To insert at a position of list\nPress 7.To delete a node from beginning of list\nPress 8.To delete a node from last of list\nPress 9.To delete a node from given position of list\n");
	while(getans2()){
		printf("Choose from the menu or press 0 to exit:");
		scanf("%d",&n);
		if (n==1){
			head=createnode();
			node=head;
			tail=head;
			putdata(node);
  			node->prev=0;
  			len+=1;
			while(getans1()){
				node->next=createnode();
	    		node->next->prev=node;
	    		node=node->next;
	    		putdata(node);
	    		tail=node;
	    		len+=1;
			}
			tail->next=head;
			head->prev=tail;
   	}
   	else if (n==2)
		{
			showdata1(head,len);
		}
   	else if (n==3)
		{
			showdata2(tail,len);
		}
		else if (n==4)
		{
			a=IAB(head,tail,len);
			if(a->data==1){
				head=tail=a->prev;
				len=a->data;
			}
			else{
				head=a->prev;
				len=a->data;
			}
		}
		else if (n==5)
		{
			a=IAE(head,tail,len);
			if(a->data==1){
				head=tail=a->next;
				len=a->data;
			}
			else{
				len=a->data;
				tail=a->next;
			}
		}
		else if (n==6)
		{
			struct node *a;
			a=IAP(head,tail,len);
			if(a->data==1){
				head=tail=a->next;
				len=a->data;
			}
			else if (a->data==0 & a->next==0 & a->prev==0){
				printf("Invalid position\n");
			}
			else if (a->data!=0 & a->next==0 & a->prev!=0){
				head=a->prev;
				len=a->data;
			}
			else if(a->data!=0 & a->next!=0 & a->prev==0){
				tail=a->next;
				len=a->data;
			}
			else if(a->data!=0 & a->next==0 & a->prev==0){
				len=a->data;
			}
		}
		else if (n==7){
			if(len==0){
				printf("List is empty\n");
			}
			else{
				a=DFB(head,tail,len);
				if (a->data==0){
					head=tail=0;
					len=0;
				}
				else{
					len=a->data;
					head=a->prev;
				}
			}
		}
		else if (n==8){
			if(len==0){
				printf("List is empty\n");
			}
			else{
				a=DFE(tail,head,len);
				if (a->data==0){
					tail=head=0;
					len=0;
				}
				else{
					len=a->data;
					tail=a->next;
				}
			}
		}
		else if (n==9){
			if(len==0){
				printf("List is empty\n");
			}
			else{
		 		struct node *a=DFP(head,tail,len);
				if (a->data==0){
					len=a->data;
				}
				else if (a->data==0 & a->next==0 & a->prev==0){
					printf("Invalid position\n");
					len=0;
				}
				else if (a->data!=0 & a->next==0 & a->prev!=0){
					head=a->prev;
					len=a->data;
				}
				else if(a->data!=0 & a->next!=0 & a->prev==0){
					tail=a->next;
					len=a->data;
				}
				else if(a->data!=0 & a->next==0 & a->prev==0){
					len=a->data;
				}
			}
		}
		else{
			printf("Invalid choice\n");
		}
	}
}
