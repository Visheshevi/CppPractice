#include <iostream>

using namespace std;

bool(isSafe(int **board,int cols,int row,int n)){
  for(int i = 0;i<cols;i++){
    if(board[row][i] == 1)
      return false;
  }
  int i,j;
  for(i = row,j = cols;i>=0 && j>= 0;i--,j--){
    if(board[i][j] == 1)
      return false;
  }
  for(i = row,j = cols;i<n && j>= 0;i++,j--){
    if(board[i][j] == 1)
      return false;
  }
  return true;
}

bool recurse(int ** board,int cols,int n){
  if(cols>=n)
    return true;
  for(int i = 0;i<n;i++){
    if(isSafe(board,cols,i,n)){
      board[i][cols] = 1;
      if(recurse(board,cols+1,n))
      return true;
      board[i][cols] = 0;
    }
  }
  return false;

}

void display(int**board,int n){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
  int n;
  cout << "Enter the number of rows/cols ";
  cin >> n;
  int **board = new int*[n];
  for(int i = 0;i<n;i++)
    board[i] = new int[n];
  for(int i = 0;i<n;i++)
    for(int j = 0;j<n;j++)
      board[i][j] = 0;
  if(recurse(board,0,n))
    display(board,n);
  else
    cout << "Not possible to place" << endl;
  return 0;
}
