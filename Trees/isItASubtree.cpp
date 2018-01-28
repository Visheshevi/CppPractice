#include <iostream>
#include <vector>
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

bool areIdentical(struct node* root1, struct node* root2){
  if(root1 == NULL && root2 == NULL)
    return true;
  if(root1 == NULL || root2 == NULL)
    return false;

  if(root1->data == root2->data)
    return areIdentical(root1->left,root2->left) && areIdentical(root1->right, root2->right);
}

bool isSubTree(struct node* root1, struct node* root2){
  if(root2 == NULL)
    return true;
  if(root1 == NULL)
    return false;

  if(areIdentical(root1,root2))
    return true;

  return (areIdentical(root1->left, root2) || areIdentical(root1->right, root2));

}

void inorder(struct node* node){
  if(node == NULL)
    return;
  inorder(node->left);
  cout << node->data<<endl;
  inorder(node->right);
}

int main(){
  vector<int> vec1,vec2;
  struct node* root1;
  struct node* root2;
  root1 = newNode(5);
  root1->left = newNode(4);
  root1->right = newNode(6);
  root1->left->left = newNode(7);
  root1->left->right = newNode(2);
  root1->left->left->left = newNode(8);
  root2 = newNode(4);
  root2->left = newNode(7);
  root2->right = newNode(2);
  root2->left->left = newNode(8);
  inorder(root1);
  cout << endl <<endl;
  inorder(root2);
  cout << endl << isSubTree(root1, root2) << endl;
  return 0;
}
