#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


unordered_map<string,int> map;
int dp(vector<int> a,int size, int pos,int sum1,int sum2){

  if(pos == size){
    return abs(sum1-sum2);
  }
  string key = to_string(pos) + "|" + to_string(sum1);
  if(map.find(key) == map.end()){
    map[key] = min(dp(a,size,pos+1,sum1+a[pos],sum2),dp(a,size,pos+1,sum1,sum2+a[pos]));
  }
  return map[key];

}

int main(){
  vector<int> a;
  int elements;
  int temp;
  cout << "Enter the number of elements ";
  cin >> elements;
  cout << "Enter the elements "<< endl;
  for(int i = 0;i<elements;i++){
    cin >> temp;
    a.push_back(temp);
  }
  int size = a.size();
  cout << "Answer is " ;
  cout << dp(a,size,0,0,0) << endl;
  return 0;
}
