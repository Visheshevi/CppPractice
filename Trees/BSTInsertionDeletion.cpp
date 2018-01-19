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

int max(int a,int b){
	return (a>=b) ? a: b;
}

int height(struct node* node){
	if(node == NULL)
		return 0;
	return 1+ max(height(node->left), height(node->right));

}

bool isBalanced(struct node* node){
	if(node == NULL)
		return true;
	int left_height = height(node->left);
	int right_height = height(node->right);
	//cout<<left_height<<endl;
	if(abs(left_height - right_height) <= 1)
		return true;
	//cout<<abs(left_height - right_height)<<endl;
	return false;
}

void deleteNode(struct node* node, int val){
	struct node* previous = NULL;
	bool found = false;
	if(node == NULL){
		cout<<"Nothing to delete as tree is not yet planted or has been cut to create paper."<<endl;
	}
	while(node != NULL){
		if(node->data == val){
			found = true;
			break;
		}
		else{
			previous = node;
			if(val < node->data)
				node = node->left;
			else if(val > node->data)
				node = node->right;
		}
	}
	if(found == false)
		cout<<"mangoes do not grow on peepal tree"<<endl;
	else{
		if(node->left == NULL && node->right == NULL){
			if(previous->left == node){
				previous->left = NULL;
			}	
			if(previous->right == node){
				previous->right = NULL;
			}
			delete node;
		}

		else if(node->left != NULL && node->right == NULL){
			previous->right = node->left;
			delete node;
		}
		else if(node->left == NULL && node->right != NULL){
			previous->left = node->right;
			delete node;
		}
//If this comment still present, there is something wrong with the deletion process. Needs to be corrected.
		else{
			struct node* check = node->right;
			if(node->left == NULL && node->right == NULL){
				node = check;
				delete check;
				node->right = NULL;
			}

			if(node->left->right != NULL){
				struct node* temp = node->left->right;
				struct node* prev_temp = node->left;
				while(temp->right != NULL){
					prev_temp = temp;
					temp = temp->right;
				}
				node->data = temp->data;
				delete temp;
				prev_temp->right = NULL;
			}
			else{
				struct node* temp = node->left;
				node->data = temp->data;
				node->right = temp->right;
				delete temp;
			}

		}
	}

	
}

int main(){
	int arr[10];
	int index = 0;
	int i = 0;
	int flag;
	struct node* root;
	//flag = deleteNode(root,4);
	//cout<<flag<<endl<<endl;
	root = newNode(8);
	root->left = newNode(3);
	root->left->left = newNode(1);
	root->right = newNode(10);
	root->left->right = newNode(6);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(7);
	root->right->right = newNode(14);
	root->right->right->left = newNode(13);
	root->right->right->right = newNode(17);
	root->right->right->right->left = newNode(16);
	root->right->right->right->right = newNode(20);
	//cout<<root->right->right->right->right->right->data<<endl;
	inorder(root);
	deleteNode(root,17);
	inorder(root);
	
	//insert(root,5);
	//inorder(root);
	//if(isBalanced(root))
	//	cout<<"isBalanced"<<endl;
	//else
	//	cout<<"is not Balanced"<<endl;
	//insert(root,5);
	//inorder(root);
	//cout<<search(root,20,0)<<endl;
	return 0;
}