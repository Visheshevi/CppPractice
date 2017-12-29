#include<iostream>
#include<cstdlib>

using namespace std;
/*Implementing a Binary Tree */
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int val){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
};
/* Implementation of binary tree done */

// In order traversal
void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}

// Pre order traversal
void preorder(struct node* node){
	if(node == NULL)
		return;
	cout<<node->data<<endl;
	preorder(node->left);
	preorder(node->right);
}

// Post order traversal
void postorder(struct node* node){
	if(node == NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<endl;
}

int main(){
	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->right->left = newNode(5);
	//cout<<root->left->data<<endl;
	inorder(root);	
	cout<<endl<<endl;
	preorder(root);
	cout<<endl<<endl;
	postorder(root);
	return 0;
}