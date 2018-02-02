#include <iostream>
#include <cstdlib>

#define TABLE_SIZE 20

using namespace std;

struct employee{
  int key;
  int age;
  char name[30];
  struct employee* next;
};

struct linkedEmployee{
  struct employee* head;
  int count;
};

struct linkedEmployee* hash = NULL;

struct employee* newNode(int key, int age, char* name){
  struct employee* temp = (employee *)malloc(sizeof(struct employee));
  temp->key = key;
  temp->age = age;
  strcpy(temp->name, name);
  temp->next = NULL;
  return temp;
}

void insert(int key, int age, char *name, int numOfElements){
  int hashIndex = key % numOfElements;
  struct employee* temp = newNode(key, age, name);
  if(!hash[hashIndex].head){
    hash[hashIndex].head = temp;
    hash[hashIndex].count = 1;
    return;
  }
  temp->next = hash[hashIndex].head;
  hash[hashIndex].head = temp;
  hash[hashIndex].count++;
  return;
}

void deleteElement(int key, int numOfElements){
  int hashIndex = key % numOfElements;
  struct employee *myNode, *prev;
  myNode = hash[hashIndex].head;
  if(!myNode){
    cout << "Data not present" << endl;
  }
  prev = myNode;
  while(1){
    if(myNode->key == key){
      if(myNode == hash[hashIndex].head){
        hash[hashIndex].head = myNode->next;
      }
      else{
        prev->next = myNode->next;
      }
      hash[hashIndex].count--;
      free(myNode);
      cout << "Succesfully deleted " << endl;
      break;
    }
    prev = myNode;
    myNode = myNode ->next;
    if(myNode == NULL){
      cout << "Data not present" << endl;
      return;
    }
  }
}

void display(int key, int n){
  int hashIndex = key % n;
  int flag = 0;
  struct employee* temp = hash[hashIndex].head;
  if(!hash[hashIndex].head ){
    cout << "I can't find nothing, dude" << endl;
    return;
  }

  while(temp->key != key || temp == NULL){
    temp = temp->next;

    if(temp == NULL){
      flag = 1;
      break;
    }
  }
  if(flag == 1){
    cout << "First get the guy registered, then enquire" << endl;
    return;
  }
  cout << "the guy is present " << "with name " << temp->name<< endl ;


}

int main(){
  int age,key;
  char* name[30];
  int n = 5;
  hash = (struct linkedEmployee *)calloc(n,sizeof(struct linkedEmployee));
  insert(17,25,"Vishesh",n);
  insert(22,25,"Bro",n);
  insert(4,25,"Bhai",n);
  insert(3,25,"yoyo",n);
  insert(2,25,"aaluye",n);
  deleteElement(16,n);
  display(2,n);
  return 0;
}
