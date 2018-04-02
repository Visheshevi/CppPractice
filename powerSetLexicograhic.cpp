#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void findPermutations(string str,int n,int index,string curr){
  if(index == n)
    return;
  cout << curr << endl;
  for(int i = index+1;i<n;i++){
    curr = curr + str[i];
    findPermutations(str,n,i,curr);

    curr = curr.erase(curr.size()-1);
  }
  return;
}


int main(){
  string str = "cabrowski";
  sort(str.begin(),str.end());
  findPermutations(str,str.size(),-1,"");
  return 0;
}
