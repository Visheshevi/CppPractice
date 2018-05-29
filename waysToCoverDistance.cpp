#include <iostream>

using namespace std;

void dp(int dist,int &count,int covered){
  if(covered == dist){
    ++count;
  }
  else if(covered < dist){
    dp(dist,count,covered+1);
    dp(dist,count,covered+2);
    dp(dist,count,covered+3);
  }
}

int main(){
  int dist, count = 0;
  cout << "Enter the distance ";
  cin >> dist;
  dp(dist,count,0);
  cout << count << endl;
  return 0;
}
