#include<iostream>
#include<cstdlib>

using namespace std;

struct Node{
	int data;
	int min;
	Node *next;
};
struct Node *top =NULL;

void push(int val){
	struct Node* temp = new Node;
	temp = (Node *)malloc(sizeof(Node));
	temp->data = val;
	if(top==NULL){
		temp->next = NULL;
		temp->min = val;
	}
	else{
		if(top->min >val)
			temp->min = val;
		else
			temp->min = top->min;
		temp->next = top;
	}
	top = temp;
	cout<<top->data<<endl;
}

void pop(){
	if(top==NULL)
		cout<<"empty"<<endl;	
	else{	
		Node * temp;
		cout<<top->data<<endl;	
		temp = top;
		top = top->next;	
		free(temp);	
			
	}
}

void peek(){
	if(top==NULL){
		cout<<"empty"<<endl;	
	}
	else
		cout<<top->data<<endl;
}

void minimum(){
	if(top==NULL){
		cout<<"Empty"<<endl;
	}
	else{
		cout<<top->min<<endl;
	}

}
int main(){
	
	push(2);
	push(3);	
	push(4);
	push(1);
	push(5);
	push(6);
	cout<<endl<<endl;
	minimum();
	pop();
	pop();
	pop();
	minimum();
	return 0;
	
}