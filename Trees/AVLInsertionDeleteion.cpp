#include <iostream>
#include <cstdlib>

using namespace std;
 
int heightOfTree(struct node* temp); 
int balance(struct node* temp);
struct node{
	int data;
	struct node* left;
	struct node* right;
	int height;
};

struct node* newNode(int val){
	struct node* temp = (node *)malloc(sizeof(struct node));
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	return temp;
}

struct node* rightRotate(struct node* temp){
	struct node* a = temp->left;
	struct node* b = a->right;

	a->right = temp;
	temp->left = b;
	temp->height = heightOfTree(temp);
	a->height = heightOfTree(a);
	//temp->height = 1 + max(heightOfTree(temp->left),heightOfTree(temp->right));
	//a->height = 1 + max(heightOfTree(a->left),heightOfTree(a->right));

	return a;

}

struct node* leftRotate(struct node* temp){
	struct node* a = temp->right;
	struct node* b = a->left;
	a->left = temp;
	temp->right = b;
	a->height = heightOfTree(a);
	temp->height = heightOfTree(temp);
	return a;

}

struct node* insert(struct node* temp, int val){
	if(temp == NULL){
		return (newNode(val));	
	}
	if(val>temp->data)
		temp->right = insert(temp->right,val);
	else if(val<temp->data)
		temp->left = insert(temp->left,val);
	else
		return temp;

	temp->height = heightOfTree(temp);
	int balanceFactor = balance(temp);

	if(balanceFactor > 1 && val < temp->left->data)
		return rightRotate(temp);

	if(balanceFactor < -1 && val > temp->right->data)
		return leftRotate(temp);

	if(balanceFactor >1 && val > temp->left->data){
		temp->left = leftRotate(temp->left);
		return rightRotate(temp);
	}

	if(balanceFactor < -1 && val < temp->right->data){
		temp->right = rightRotate(temp->right);
		return leftRotate(temp);
	}

	return temp;
}

void inorder(struct node* temp){
	if(temp == NULL)
		return;
	inorder(temp->left);
	cout<<temp->data<<endl;
	inorder(temp->right);
}

int heightOfTree(struct node* temp){
	if(temp == NULL)
		return 0;
	return 1 + max(heightOfTree(temp->left),heightOfTree(temp->right));
}
int balance(struct node* temp){
	if(temp == NULL)
		return 0;
	return (heightOfTree(temp->left) - heightOfTree(temp->right));
}
struct node* findMinimum(struct node* node){
	if(node == NULL)
		return NULL;
	if(node->left = NULL)
		return node;
	else
		return findMinimum(node->left);
}

struct node* removeNode(struct node* node, int val){
	struct node* temp;
	if(node == NULL)
		return NULL;
	else if(val < node->data){
		node->left = removeNode(node->left,val);
	}
	else if(val > node->data)
		node->right = removeNode(node->right,val);
	else if(node->left != NULL && node->right != NULL){
		temp = findMinimum(node->right);
		node->data = temp->data;
		node->right = removeNode(node->right,node->data);

	}
	else{
		temp = node;
		if(node->left == NULL){
			node = node->right;
		}
		else if(node->right == NULL){
			cout<<"brio"<<endl;
			node = node->left;
		}
		delete temp;
	}
	if(node == NULL)
		return node;

	node->height = heightOfTree(node);

	if(heightOfTree(node->left) - heightOfTree(node->right) == 2){
		if(heightOfTree(node->left->left) - heightOfTree(node->left->right) == 1)
			return leftRotate(node);
		else{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	if(heightOfTree(node->left) - heightOfTree(node->right) == -2){
		if(heightOfTree(node->right->right) - heightOfTree(node->right->left) == 1)
			return rightRotate(node);
		else{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	return node;
}

bool isPresent(struct node* node,int val){
	if(node == NULL)
		return false;
	if(val < node->data)
		return isPresent(node->left,val);
	else if(val > node->data)
		return isPresent(node->right,val);
	return true;
}
int main(){
	struct node* root;
	root = insert(root, 10);
  	root = insert(root, 20);
  	root = insert(root, 30);
  	root = insert(root, 40);
  	root = insert(root, 50);
  	cout<<heightOfTree(root)<<endl;
  	//cout<<root->data<<endl;
  	//cout<<balance<<endl<<endl<<endl;
  	//cout<<root->right->right->data<<endl<<endl;
  	root = insert(root, 25);
	inorder(root);
	cout<<endl;
	//removeNode(root,25);
	//inorder(root);
	cout<<isPresent(root,21)<<endl;
	return 0;
}
