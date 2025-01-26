#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *create(){
	int n;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter -1 to stop entering nodes:");
	scanf("%d",&n);
	if(n==-1){
		return 0;
	}
	newnode->data=n;
	printf("Enter data to left node of %d\n",n);
	newnode->left=create();
	printf("Enter data to right node of %d\n",n);
	newnode->right=create();
	return newnode;
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
	int a;
	struct node *root;
	root=create();
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
