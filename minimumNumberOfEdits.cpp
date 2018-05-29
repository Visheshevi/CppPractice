#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int minimum(int a,int b,int c){
  return min(min(a,b),c);
}

int numEdits(string str1,string str2,int m,int n){
  if(m == 0)
    return n;
  else if(n == 0)
    return m;
  else if(str1[m-1] == str2[n-1])
    return numEdits(str1,str2,m-1,n-1);
  else{
    return 1 + minimum(numEdits(str1,str2,m,n-1),numEdits(str1,str2,m-1,n),numEdits(str1,str2,m-1,n-1));

  }
}

int main(){
  string str1,str2;
  cout << "Enter first string ";
  cin >> str1;
  cout << "Enter second string ";
  cin >> str2;
  cout << numEdits(str1,str2,str1.length(),str2.length()) << endl;
  return 0;
}
