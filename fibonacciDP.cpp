#include <iostream>

using namespace std;

void factorial(int n){
  int *b;
  b = new int[n];
  for(int i =0;i<=n;i++){
    b[i] = 0;
  }
  b[0] = b[1] = b[2] = 1;
  for(int i = 3;i<=n;i++){
    if(b[i] == 0){
      b[i] = b[i-2] + b[i-1];
    }
  }
  for(int i = 1;i<=n;i++){
    cout << b[i] << " ";
  }
  cout << endl;
}

int main(){
  int n;
  cout << "Enter a number ";
  cin >> n;
  factorial(n);
  return 0;
}
