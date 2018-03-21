#include <iostream>
#include <algorithm>
using namespace std;

int recurse(int ** mat,int **calculations,int a,int b, int rows,int cols){
  if((a >= rows-1) && (b >= cols-1)){
    return mat[rows-1][cols-1];
  }
  if(a == rows-1){
    return mat[a][b] + recurse(mat,calculations,a,b+1,rows,cols);
  }
  else if(b == cols-1){
    return mat[a][b] + recurse(mat,calculations,a+1,b,rows,cols);
  }
  else{
    if(calculations[a][b] > 0){
      return calculations[a][b];
    }
    else{
      calculations[a][b] = max(mat[a][b] + recurse(mat,calculations,a+1,b,rows,cols),mat[a][b] + recurse(mat,calculations,a,b+1,rows,cols));
      return calculations[a][b];
    }
  }
  return 0;
}

int pacmanScore(int **mat,int rows, int cols){
  //int rows = sizeof(mat)/sizeof(mat[0]);
  //int cols = sizeof(mat[0])/sizeof(int);
  //cout << rows << "  "  << cols << endl;
  cout << mat[2][2] << endl;
  if(rows == 0  && cols == 0){
    return 0;
  }
  if(rows == 1 && cols == 1){
    return mat[0][0];
  }
  int** calculations = new int*[rows];
  for(int i = 0; i < rows; ++i)
    calculations[i] = new int[cols];
  for(int i =0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      //*(*(calculations+i)+j) = 0;
      calculations[i][j] = 0;
    }
  }
  for(int i = 0;i<rows;i++){
    for(int j = 0;j<cols;j++){
      //cout << *(*(calculations+i)+j) << " ";
      cout << calculations[i][j] << " ";
    }
    cout << endl;
  }
  return recurse(mat,calculations,0,0,rows,cols);
  //return 0;
}

int main(){
  int **mat;
  mat = new int*[3];
  for(int i =0;i<3;i++){
    mat[i] = new int[4];
  }
  for(int i =0;i<3;i++){
    for(int j = 0;j<4;j++){
      cin >> *(*(mat+i)+j);
    }
  }
  //mat[3][4] = {{0,3,2,8},{1,4,9,3},{6,2,2,0}};
  for(int i = 0;i<3;i++){
    for(int j = 0;j<4;j++){
      cout << *(*(mat+i)+j) << " ";
    }
    cout << endl;
  }
  int a = pacmanScore(mat,3,4);
  cout << a << endl;
  return 0;
}
