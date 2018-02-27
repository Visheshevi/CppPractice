#include <iostream>
#include <cstdlib>

using namespace std;

struct adjList{
  int data;
  struct adjList* next;
};

struct listPointer{
  struct adjList* head;
};

struct Graph{
  int V;
  struct listPointer* array;
};

struct adjList* newNode(int src){
  struct adjList* temp = (adjList *)malloc(sizeof(struct adjList));
  temp->data = src;
  temp->next = NULL;
  return temp;
}

struct Graph* createGraph(int vertices){
  struct Graph* G = (Graph *)malloc(sizeof(struct Graph));
  G->V = vertices;
  G->array = (listPointer *)malloc(vertices*sizeof(struct listPointer));
  for(int i = 0;i<vertices;i++){
    G->array[i].head = NULL;
  }
  return G;
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
}

bool isThereARoute(struct Graph* G, int src, int dest){
  if(G->array[src].head == NULL){
    return false;
  }
  struct adjList* check = G->array[src].head;
  while(check){
    if(check->data == dest)
      return true;
    check = check->next;
  }
  check = G->array[src].head;
  while(check){
    bool z = isThereARoute(G,check->data,dest);
    if(z)
      return true;
    check = check->next;

  }
  return false;
}

void display(struct Graph* g){
  for(int i = 0;i < g->V; i++){
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
  //addEdge(G,2,3);
  //addEdge(G,2,3);
  addEdge(G,1,2);
  addEdge(G,2,4);
  addEdge(G,2,0);
  addEdge(G,4,0);
  addEdge(G,4,3);
  cout<<isThereARoute(G,2,1) << endl;
  return 0;
}
