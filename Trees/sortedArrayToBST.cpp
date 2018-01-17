#include<iostream>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newNode(int val){
	struct node *temp = (node *)malloc(sizeof(node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* createBST(int arr[],int start, int end,struct node* node){
	if(start>end)
		return NULL;
	int mid = (start+end)/2;
	node = newNode(arr[mid]);
	node->left = createBST(arr,start,mid-1,node->left);
	node->right = createBST(arr,mid+1,end,node->right);
	return node;
}

void inorder(struct node *node){
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(n);
	struct node* root;
	root = createBST(arr,0,n-1,root);	
	inorder(root);
	return 0;
}
