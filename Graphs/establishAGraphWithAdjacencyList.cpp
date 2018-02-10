#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

struct adjList{
  int data;
  adjList* next;
};

struct listPointer{
  struct adjList* head;
};

struct Graph{
  int V;
  struct listPointer* array;
};

struct adjList* newNode(int val){
  struct adjList* temp = (adjList *)malloc(sizeof(struct adjList));
  temp->data = val;
  temp->next = NULL;
  return temp;
}

struct Graph* createGraph(int vertices){
  struct Graph* temp = (struct Graph *)malloc(sizeof(struct Graph));
  temp->V = vertices;
  temp->array = (struct listPointer*)malloc(vertices * sizeof(struct listPointer));
  for(int i = 0;i<vertices;i++){
    temp->array[i].head = NULL;
  }
  return temp;
}

void addEdge(struct Graph* g,int src, int dest){
  struct adjList* temp = newNode(dest);
  int flag = 0;
  /* To add an edge from source to destination */
  if(g->array[src].head == NULL){
    g->array[src].head = temp;
  }
  else{
    struct adjList* check = g->array[src].head;
    while(1){
      if(check->data == dest){
        flag = 1;
        cout << "flag " << flag << endl;
        break;
      }
      if(check->next != NULL)
        check = check->next;
      else{
        check->next = temp;
        break;
      }
    }
  }
  /* Add an edge from destination to source as we creating an undirected graph */
  temp = newNode(src);
  flag = 0;
  if(g->array[dest].head == NULL){
    g->array[dest].head = temp;
  }
  else{
    struct adjList* check = g->array[dest].head;
    while(1){
      if(check->data == src){
        flag = 1;
        break;
      }
      if(check->next != NULL)
        check = check->next;
      else{
        check->next = temp;
        break;
      }
    }
    if(flag == 1)
      cout << "Edge cannot be added as it is already present " << endl;
  }
}

void deleteEdge(struct Graph* g,int src, int dest){
  struct adjList* temp = g->array[src].head;
  struct adjList* temp_prev = temp;
  if(temp == NULL){
    cout << "Nothing to delete here. " << endl;
    return;
  }
  if(temp->data == dest){
    g->array[src].head = temp->next;
  }
  else{

    while(temp->next != NULL){
      if(temp->data != dest){
        temp_prev = temp;
        temp = temp->next;
      }
      else{
          temp_prev->next = temp->next;
          free(temp);
      }
    }
    if(temp->next == NULL && temp->data == dest){
      temp_prev->next = temp->next;
    }
  }
  temp = g->array[dest].head;
  temp_prev = temp;
  if(temp == NULL){
    cout << "Nothing to delete here. " << endl;
    return;
  }
  if(temp->data == src){
    g->array[dest].head = temp->next;
  }
  else{

    while(temp->next != NULL){
      if(temp->data != src){
        temp_prev = temp;
        temp = temp->next;
      }
      else{
          temp_prev->next = temp->next;
          free(temp);
      }
    }
    if(temp->next == NULL && temp->data == dest){
      temp_prev->next = temp->next;
    }
  }
}

vector<int> deleteNode(struct Graph* g,int node, vector<int> deletedNodes){
  struct adjList* temp = g->array[node].head;
  vector<int> other_edges;
  if(temp == NULL){
    cout << "Dont you think there should be a node here, to delete" << endl;
    return deletedNodes;
  }
  while(temp){
    other_edges.push_back(temp->data);
    temp = temp->next;
  }
  deletedNodes.push_back(node);
  delete(g->array[node].head);
  struct adjList* temp_prev = temp;
  for(int i = 0;i<other_edges.size();i++){
    temp = g->array[other_edges[i]].head;
    if(temp->data == node){
      g->array[other_edges[i]].head = temp->next;
    }
    else{

      while(temp->next != NULL){
        if(temp->data != node){
          temp_prev = temp;
          temp = temp->next;
        }
        else{
            temp_prev->next = temp->next;
            free(temp);
        }
      }
      if(temp->next == NULL && temp->data == node){
        temp_prev->next = temp->next;
      }
    }
  }
  return deletedNodes;
}

void display(struct Graph* g, vector <int> deletedNodes){
  for(int i = 0;i < g->V; i++){
    if(find(deletedNodes.begin(),deletedNodes.end(),i) != deletedNodes.end())
      continue;
    struct adjList* temp = g->array[i].head;
    cout << "The edges connected to the vertice " << i << " are " ;
    while(temp){
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout <<endl;
  }
}

int main(){
  int n;
  cout << "Enter the number of vertices in graph ";
  cin >> n;
  struct Graph* G = createGraph(n);
  vector<int> deletedNodes;
  addEdge(G,2,3);
  addEdge(G,2,3);
  addEdge(G,1,2);
  addEdge(G,2,4);
  addEdge(G,2,0);
  addEdge(G,1,0);
  addEdge(G,4,3);
  display(G, deletedNodes);
  deletedNodes = deleteNode(G,0,deletedNodes);
  cout << endl << endl;
  display(G, deletedNodes);
  return 0;
}
