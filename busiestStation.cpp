#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(){
  vector< vector<int> > data = {{148779925,14,1},{148779925,4,0},{148779925,2,0},{1487800378,10,1},{1487801478,18,0},{1487801478,18,1},{1487901013,1,0},{1487901211,7,1},{1487901211,7,0}};
  unordered_map<int,int> map;
  int busiest = 0;
  int temp = 0;
  for(int i =0;i<data.size();i++){
    if(map.find(data[i][0]) == map.end()){
      if(data[i][2] == 1){
        map.insert({data[i][0],data[i][1]});
      }
      else{
        map.insert({data[i][0],-data[i][1]});
      }
    }
    else{
      if(data[i][2] == 1)
        map.find(data[i][0])->second += data[i][1];
      else
        map.find(data[i][0])->second -= data[i][1];
    }
  }
  for(auto it:map){
    if(temp+it.second > temp){
      busiest = it.first;
    }
    temp += it.second;
  }
  cout << busiest << endl;
  return 0;
}
