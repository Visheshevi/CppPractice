#include <iostream>

using namespace std;

bool recurse(int **maze,int **cache,int a,int b,int rows,int cols){
  cache[a][b] = 1;
  if(a == rows-1 && b == cols-1){
    return true;
  }
  if(a == rows-1){
    for(int i  = maze[a][b];i>0;i--){
      if(maze[a][b+i] != 0)
        return recurse(maze,cache,a,b+i,rows,cols);
    }
    cache[a][b] = 0;
  }
  else if(b == cols-1){
    for(int i  = maze[a][b];i>0;i--){
      if(maze[a+i][b] != 0)
        return recurse(maze,cache,a+i,b,rows,cols);
    }
    cache[a][b] = 0;
  }
  else{
    for(int i  = maze[a][b];i>0;i--){
      if(maze[a][b+i] != 0){
        if(recurse(maze,cache,a,b+i,rows,cols))
          return true;
      }
      if(maze[a+i][b] != 0){
        if(recurse(maze,cache,a+i,b,rows,cols))
        return true;
      }
    }
    cache[a][b] = 0;
    return false;
  }
  return false;
}

bool findSolution(int **maze,int ** cache,int rows,int cols){
  return recurse(maze,cache,0,0,rows,cols);
}

int main(){
  int rows,cols;
  cout <<"Enter the number of rows ";
  cin >> rows;
  cout << "Enter the number of cols ";
  cin >> cols;
  int **maze = new int*[rows];
  for(int i = 0;i<rows;i++){
    maze[i] = new int[cols];
  }
  cout << "Enter the maze " << endl;
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      cin >> maze[i][j];
    }
  }
  int **cache = new int*[rows];
  for(int i = 0;i<rows;i++){
    cache[i] = new int[cols];
  }
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      cache[i][j] = 0;
    }
  }
  if(findSolution(maze,cache,rows,cols)){
    for(int i = 0;i<rows;i++){
      for(int j = 0;j<cols;j++){
        cout << cache[i][j] << " ";
      }
      cout << endl;
    }
  }
  else{
    cout << "No solution, bruh!! Sorry man." << endl;
  }

  return 0;
}
