#include <iostream>

using namespace std;

int max(int f,int s){
  return (f>s)?f:s;
}
int lcs(char *a,char *b,int m, int n){
  int **memory = new int*[m+1];
  for(int i = 0;i<=m;i++){
    memory[i] = new int[n+1];
  }
  for(int i =0;i<=m;i++){
    for(int j = 0;j<= n;j++){
      if(i == 0 || j == 0){
        memory[i][j] = 0;
      }
      else if(a[i-1] == b[j-1]){
        memory[i][j] = 1 + memory[i-1][j-1];
      }
      else{
        memory[i][j] = max(memory[i-1][j],memory[i][j-1]);
      }
    }
  }
  return memory[m][n];
}


int main(){
  char a[] = "Vishesh";
  char b[] = "iwehdeh";
  cout << lcs(a,b,7,7);
  return 0;
}
