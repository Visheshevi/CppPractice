#include <iostream>

using namespace std;

int main(){
  int a,b;
  cout << "Input number one ";
  cin >> a;
  cout << "Input the other number ";
  cin >> b;
  int count = 0;
  a = a^b;
  if(a&1 == 1)
    count++;
  while(a!=0){
    a = a>>1;
    if(a&1 == 1)
      count++;
  }
  cout << count << endl;
  return 0;
}
