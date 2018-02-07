#include <iostream>
#include <cstdlib>

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
  temp->next = g->array[src].head;
  g->array[src].head = temp;

  temp = newNode(src);
  temp->next = g->array[dest].head;
  g->array[dest].head = temp;
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
  addEdge(G,2,3);
  addEdge(G,1,2);
  addEdge(G,2,4);
  addEdge(G,2,0);
  addEdge(G,1,0);
  addEdge(G,4,3);
  display(G);
  return 0;
}
