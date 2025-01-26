#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(int n){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->left=0;
	newnode->right=0;
	return newnode;
}
struct node *insert(struct node *root){
	int n;
	printf("Enter data you want to insert or press -1 to stop:");
	scanf("%d",&n);
	if(n==-1){
		return 0;
	}
	if(root->data>n){
		root->left=create(n);
		insert(root->left);
	}
	else{
		root=root->right=create(n);
		insert(root->right);
	}
}
void inorder(struct node *root){
	if(root==0){
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
	printf("\n");
}
void preorder(struct node *root){
	if(root==0){
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
	printf("\n");
}
void postorder(struct node *root){
	if(root==0){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
	printf("\n");
}
int getans(){
	int a;
	printf("Enter 1 to continue and 0 to stop\n");
	scanf("%d",&a);
	return a;
}
void main(){
	int a,n;
 	struct node *root;
 	printf("Enter root:");
	scanf("%d",&n);
	root=create(n);
	insert(root);
	printf("Enter 1. to print inorder\nEnter 2. to print preorder\nEnter 3, to print postorder\n");
	while(getans()){
		printf("Enter your choice from menu:\n");
		scanf("%d",&a);
		if(a==1){
			inorder(root);
		}
		else if(a==2){
			preorder(root);
		}
		else if(a==3){
			postorder(root);
		}
		else{
			printf("Invalid choice\n");
		}
	}
 }
