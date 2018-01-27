#include <iostream>
#include <cstdlib>
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

/* using 2 tree traverses */
bool findingThePath(struct node* node, vector<int> &path, int val){
  if(node == NULL)
    return false;
  path.push_back(node->data);

  if(node->data == val)
    return true;
  if((node->left != NULL) && findingThePath(node->left,path,val))
    return true;
  if((node->right != NULL) && findingThePath(node->right,path,val))
    return true;
  path.pop_back();
  return false;
}

/* using 2 tree traerses */
void commonAncestor(struct node* node, int first, int second){
  vector<int> first_path, second_path;
  int ancestor = 0;
  if(findingThePath(node, first_path, first) == false || findingThePath(node, second_path, second) == false){
    cout << "can't locate ancestor. Consider this as my shortcoming."<< endl;
    return;
  }

  for(int i =0;i<first_path.size();i++)
    cout << first_path[i] << "\t";
  cout <<endl<<endl;
  for(int i =0;i<second_path.size();i++)
    cout << second_path[i] << "\t";
  cout <<endl<<endl;
  for(int i = 0;i < first_path.size() && i < second_path.size();i++){
    if(first_path[i] != second_path[i]){
      ancestor = i-1;
      break;
    }
  }
    cout << "ancestor is " << first_path[ancestor];

}

struct node* singleTraversalAncestor(struct node* node, int val1, int val2, bool &v1, bool &v2){
  if(node == NULL){
    return NULL;
  }

  if(node->data == val1){
    v1 = true;
    return node;
  }

  if(node->data == val2){
    v2 = true;
    return node;
  }

  struct node* temp_left = singleTraversalAncestor(node->left,val1, val2, v1, v2);
  struct node* temp_right = singleTraversalAncestor(node->right,val1, val2, v1, v2);

  if(temp_right && temp_left ){
    return node;
  }

  return (temp_left != NULL)?temp_left : temp_right;

}


void inorder(struct node* node){
  if(node == NULL)
    return;
  inorder(node->left);
  cout << node->data<<endl;
  inorder(node->right);
}
bool isTheOtherPresent(struct node* node,int val){
  if(node == NULL)
    return false;
  if(node->data == val || isTheOtherPresent(node->left,val) || isTheOtherPresent(node->right, val))
    return true;
  return false;
}
struct node* findingAncestor(struct node* node, int val1, int val2){
  bool v1 = false,v2 = false;
  struct node* temp = singleTraversalAncestor(node, val1, val2, v1, v2);

  if(v1 && v2)
    return temp;
  if(v1 && (isTheOtherPresent(temp,val2)))
    return temp;
  if(v2 && (isTheOtherPresent(temp, val1)))
    return temp;
  return NULL;

}
int main(){
  struct node* root;
  root = newNode(10);
  root->left = newNode(21);
  root->right = newNode(22);
  root->right->left = newNode(12);
  root->right->left->left = newNode(1);
  root->right->left->right = newNode(5);
  root->left->right = newNode(4);
  root->left->left = newNode(8);
  inorder(root);
  //commonAncestor(root, 5,1);
  cout <<  endl << endl;
  struct node* t = findingAncestor(root, 8,1);
  if(t != NULL)
    cout << t->data;
  else
    cout << "both the values are not present" << endl;
  return 0;
}
