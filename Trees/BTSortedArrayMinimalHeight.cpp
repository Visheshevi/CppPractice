#include <iostream>
#include <cstdlib>

using namespace std;


struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int val){
	struct node* temp = (node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* createBST(int arr[],int start,int end){
	struct node* temp = (node *)malloc(sizeof(struct node));
	if(start>end)
		return NULL;
	int mid = (start+end)/2;
	temp->data = arr[mid];
	//node->data = temp->data;
	//cout<<"Node ka data "<<temp->data<<endl;	
	temp->left = createBST(arr,start,mid-1);
	temp->right = createBST(arr,mid+1,end);
	return temp;
}


void inorder(struct node* node){
	if(node == NULL)
		return;
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}

int heightOfTree(struct node* node){
	if(node == NULL)
		return 0;
	return 1 + max(heightOfTree(node->left),heightOfTree(node->right));
}

int main(){
	struct node* root = (node *)malloc(sizeof(node));
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(arr)/sizeof(int);
	int height= 0;
	root = createBST(arr,0,n-1);
	height = heightOfTree(root);
	inorder(root);
	cout<<endl;
	cout<<height<<endl;
	return 0;
}
