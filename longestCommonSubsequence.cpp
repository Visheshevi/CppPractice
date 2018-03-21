#include <iostream>
#include <algorithm>


using namespace std;

int longestsubsequence(char a[],char b[]){
  int a_length = sizeof(a)/sizeof(char);
  int b_length = sizeof(b)/sizeof(char);
  for(int i =a_length;i>0;i--){
    a[i] = a[i-1];
  }
  for(int i = b_length;i>0;i--){
    b[i] = b[i-1];
  }
  int common[a_length+1][b_length+1];
  for(int i = 0;i<=a_length;i++){
    common[i][0] = 0;
  }
  for(int i = 0;i<=b_length;i++){
    common[0][i] = 0;
  }
  for(int i = 1;i<=a_length;i++){
    for(int j = 1;j<=b_length;j++){
      if(a[i] == b[j]){
        common[i][j] = common[i-1][j-1] + 1;
      }
      else{
        common[i][j] = max(common[i-1][j],common[i][j-1]);
      }
    }
  }
  return common[a_length][b_length];
}

int main(){

  char s_a[4] = {'a','b','c','b'};
  char s_b[4] = {'b','d','c','a'};
  cout << longestsubsequence(s_a,s_b);
  return 0;
}
