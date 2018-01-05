#include<iostream>

using namespace std;

#define MAX 5

class Stack{
	int top;
	public:
		int a[MAX];
		Stack(){
			top = -1;	
		}
		bool push(int val);
		int pop();
		bool isempty();
		int peek();

};


bool Stack::push(int val){
	//cout<<top<<endl;
	if(top>=MAX){
		cout<<"Stack full. Cant add anything else"<<endl;
		return false;	
	}
	else{
		top++;
		a[top] = val;
		return true;
	}
	
}

int Stack::pop(){
	if(top==-1){
		cout<<"Stack is empty"<<endl;
		return 0;	
	}
	else{
		cout<<a[top]<<endl;
		top--;
		return 1;	
	}
}

bool Stack::isempty(){
	if(top==-1){
		return true;	
	}
	return false;
}

int Stack::peek(){
	if(top == -1){
		cout<<"Nothing to peek. Stack Empty"<<endl;
		return -1;
	}
	else
		return a[top];

}


int main(){
	Stack s;
	s.push(4);
	//cout<<s.peek()<<endl;
	s.push(5);
	//cout<<s.peek()<<endl;
	s.push(6);
	s.pop();
	s.pop();
	s.pop();
	s.pop();
	//cout<<s.peek()<<endl;	
}