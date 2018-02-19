/* Based on geeks for geeks completely */
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Graph{
  int V;
  list<int> *array;

public:
  Graph(int V);
  void addEdge(int src, int dest);
  void BFS(int src);
};

Graph::Graph(int V){
  this->V = V;
  array = new list<int>[V];
}

void Graph::addEdge(int src, int dest){
  array[src].push_back(dest);
}

void Graph::BFS(int src){
  bool *visited = new bool[V];
  for(int i = 0;i<V;i++){
    visited[i] = false;
  }
  list<int> queue;
  visited[src] = true;
  queue.push_back(src);
  list<int>::iterator i;
  while(!queue.empty()){
    src = queue.front();
    cout << src << " ";
    queue.pop_front();
    for(i = array[src].begin();i != array[src].end();i++){
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

int main(){
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);
  g.BFS(2);
  return 0;
}
