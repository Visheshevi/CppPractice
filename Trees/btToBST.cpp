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

void storeInorder(struct node *node,int arr[],int *index){
	if(node == NULL)
		return;
	storeInorder(node->left,arr,index);
	arr[*index] = node->data;
	(*index)++;
	storeInorder(node->right,arr,index);
}	

void sort(int arr[],int n){
	int i,min,j;
	for(i = 0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++)
			if(arr[j] < arr[min])
				min = j;

		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}

}

void convertToBST(struct node *node,int arr[],int *index){
	if(node == NULL)
		return;
	convertToBST(node->left,arr,index);
	node->data = arr[*index];
	(*index)++;
	convertToBST(node->right,arr,index);

}




int main(){
	int arr[10];
	int index = 0;
	int i = 0;
	struct node* root = newNode(5);
	root->left = newNode(3);
	root->left->left = newNode(7);
	root->right = newNode(2);
	root->left->right = newNode(8);
	inorder(root);
	storeInorder(root,arr,&index);
	sort(arr,5);
	index = 0;
	convertToBST(root,arr,&index);
	cout<<endl<<endl<<endl;
	inorder(root);
	return 0;
}