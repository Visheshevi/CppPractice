#include<iostream>
#include<cstdlib>
using namespace std;

struct Node{
	int data;
	Node *next;
}*head;

void insertFromFront(int val){
			Node *temp;
			temp = (Node *)malloc(sizeof(Node));
			temp->data = val;
			temp->next = head;			
			head = temp;
	}

void traverse(){
	Node *temp;
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<"\t";
		temp=temp->next;	
	}
	cout<<endl;
}	

void insertAtBack(int val){
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp->data = val;
	temp->next = NULL;
	Node *find;
	find = head;
	while(find->next!=NULL){
		find = find->next;	
	}
	find->next = temp;
}

void insertAtPosition(int val,int pos){
	int i;	
	Node *temp = new Node;
	Node *find = new Node;	
	temp = (Node *)malloc(sizeof(Node));
	temp->data = val;
	find = head;
	for(i=0;i<pos-1;i++){
		find= find->next;
		if(find == NULL){
			cout<<"No such Node"<<endl;
			return;
		}		
	}
	temp->next = find->next;
	find->next = temp;
	cout<<"Data inserted successfully"<<endl;
}

void deleteFromFront(){
	Node *temp;
	temp = (Node *)malloc(sizeof(Node));
	temp = head;
	head = temp->next;
	free(temp);
}

void DeleteFromEnd(){
	Node *temp;
	Node *temp1;
	temp = (Node *)malloc(sizeof(Node));
	temp1 = (Node *)malloc(sizeof(Node));
	temp = head;	
	while(temp->next != NULL){
		temp1 = temp;		
		temp = temp->next;
	}
	temp1->next = NULL;
	free(temp);
	
	
	
}

void deleteFromPos(int pos){
	Node *temp;
	Node *temp1;
	temp = (Node *)malloc(sizeof(Node));
	temp1 = (Node *)malloc(sizeof(Node));
	temp = head;	
	int i;	
	for(i=0;i<pos-1;i++){
		temp1 = temp;		
		temp = temp->next;
	}
	temp1->next = temp->next;
	free(temp);

}

void removeDuplicates(){
	Node *find;
	Node *iter;
	Node *iter1;
	int pos = 0,i;
	find = (Node *)malloc(sizeof(Node));
	iter = (Node *)malloc(sizeof(Node));
	iter1 = (Node *)malloc(sizeof(Node));
	find = head;
	iter = find->next;
	iter1 = find;
	while(find!=NULL){	
		while(iter!=NULL){
			if(iter == NULL)
				break;
			if(iter->data == find->data){
				iter1->next = iter->next;
				free(iter 	);
				iter = iter1->next;		
			}
			else{
				iter = iter->next;
				iter1 = iter1->next;			
			}					
		}
		find = find->next;
		if(find != NULL){
			iter = find->next;
			iter1 = find;		
		}
	}						
}

void findElementPosFromLast(int pos){
	Node *temp;
	int count=0;
	int i;
	temp = (Node *)malloc(sizeof(Node));
	temp = head;
	if(head == NULL){
		cout<<"Empty list"<<endl;
		return;	
	}
	else{
		while(temp!=NULL){
			count++;
			temp = temp->next;		
		}	
	}
	temp = head;
	if(pos>count){
		cout<<"No such position"<<endl;
	}
	else{
		for(i = 0;i<count-pos;i++){
			temp = temp->next;	
		}
		cout<<temp->data<<endl;
	}	
}
//Another way could be to take to pointers and keep them pos distance apart

void deleteWithAccess(){
	Node *temp;
	Node *temp1;	
	temp = (Node *)malloc(sizeof(Node));
	temp1 = (Node *)malloc(sizeof(Node));
	//temp contains the node to which it is given access	
	temp = head->next->next->next;
	temp1 = temp->next;
	temp->data = temp1->data;
	temp->next = temp1->next;	
	delete temp1;
	
}

int main(){
	head=NULL;	
	insertFromFront(3);
	insertFromFront(4);
	insertFromFront(5);
	insertFromFront(6);
	insertFromFront(8);
	insertFromFront(7);
	insertFromFront(9);
	traverse();
	insertAtBack(8);
	traverse();
	insertAtPosition(2,2);
	traverse();	
	deleteWithAccess();	
	traverse();	
	//findElementPosFromLast(10);
	//removeDuplicates();
	//traverse();
	return 0;
}

