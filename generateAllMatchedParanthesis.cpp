#include <iostream>

using namespace std;

int main(){
  int n_open,n_close;
  char *open,*close;
  int count_1=0,count_2 = 0,count_3 = 0;
  cout << "Enter number of elements in opneing paranthesis ";
  cin >> n_open;
  cout << "Enter the number of in closing paranthesis ";
  cin >> n_close;
  open = new char[n_open];
  close = new char[n_close];
  cout << "Enter the paranthesis in open";
  for(int i =0;i<n_open;i++){
    cin >> open[i];
  }
  cout << "Enter the paranthesis in close";
  for(int i =0;i<n_close;i++){
    cin >> close[i];
  }
  for(int i = 0;i<n_open;i++){
    if(open[i] == '{')
      count_1++;
    else if(open[i] == '(')
      count_2++;
    else if(open[i] == '[')
      count_3++;
  }
  for(int i = 0;i < n_close;i++){
    if(close[i] == '}' && count_1>0){
      cout << "{}" << endl;
      count_1--;
    }
    if(close[i] == ')' && count_2 > 0){
      cout << "()" << endl;
      count_2--;
    }
    if(close[i] == ']' && count_3>0){
      cout << "[]" << endl;
      count_3--;
    }
  }
  delete [] open;
  delete [] close;
  return 0;
}
