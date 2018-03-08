#include <iostream>

using namespace std;

int main(){
  int n = 2;
  int m = 4;
  int i = 4,j=2;
  int ones = ~0;
  // cout << "Ones is equla to " <<ones<< endl;
  int before_i = ones << i+1;
  // cout << "before ones " << before_i << endl;
  int after_j = (1 << j) - 1;
  // cout << "after ones " << after_j << endl;
  int temp = before_i | after_j;
  // cout << "temp " << temp << endl;
  int finale = n & temp;
  // cout << "finale  " << finale << endl;
  finale = finale | (m<<(j));
  // cout <<"The out put is " << finale << endl;

  return 0;
}
