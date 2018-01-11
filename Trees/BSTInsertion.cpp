#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node* right;
};

struct node *newNode(int val){
	struct node *temp = (node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}

int search(struct node *node,int val,int count){
	if(node == NULL)
		return -1;
	if(val == node->data)
		return node->data;
	else{
		count++;
		if(val < node->data)
			return search(node->left,val,count);
		else
			return search(node->right,val,count);
	}

}

struct node* insert(struct node *node, int val){
	if(node == NULL){
		return newNode(val);
	}
	if(node->data > val)
		node->left = insert(node->left,val);
	if(node->data < val)
		node->right = insert(node->right, val);
	return node;
}

int main(){
	int arr[10];
	int index = 0;
	int i = 0;
	struct node* root = newNode(8);
	root->left = newNode(3);
	root->left->left = newNode(1);
	root->right = newNode(10);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	inorder(root);
	insert(root,5);
	inorder(root);
	//cout<<search(root,11,0)<<endl;
	return 0;
}