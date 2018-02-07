#include <iostream>
#include <cstdlib>

using namespace std;


struct Graph{
  int V;
};

struct Graph* createGraph(int vertices){
  struct Graph* temp = (struct Graph *)malloc(sizeof(struct Graph));
  temp->V = vertices;
  return temp;
}

void addEdge(struct Graph* g, int src, int dest, int** adjMat){
  if(src == dest || src > g->V - 1 || dest > g->V - 1){
    cout << "cant add edge from " << src << " to " << dest << " and vice versa" << endl;
    return;
  }
  adjMat[src][dest] = 1;
  adjMat[dest][src] = 1;
  cout <<"added"<<endl;
}

void displayAdjMat(int n, int** adjMat){
  for(int i = 0;i<n;i++){
    for(int j = 0;j < n;j++){
      cout <<adjMat[i][j] << " ";
    }
    cout <<endl;
  }
}

int main(){
  int n;
  cout << "Enter the number of vertices in graph ";
  cin >> n;

  /* Creating a pointer to a pointer to create a 2D matrix */
  int** adjMat = new int*[n];
  for(int i = 0;i<n;i++){
    adjMat[i] = new int[n];
  }

  /* Initialized the 2D Matrix to 0 */
  for(int i = 0;i<n;i++)
    for(int j = 0;j < n;j++)
      adjMat[i][j] = 0;

  struct Graph* G = createGraph(n);
  addEdge(G,0,1,adjMat);
  addEdge(G,2,1,adjMat);
  addEdge(G,3,2,adjMat);
  addEdge(G,4,3,adjMat);
  addEdge(G,1,4,adjMat);
  displayAdjMat(n,adjMat);
  return 0;
}
