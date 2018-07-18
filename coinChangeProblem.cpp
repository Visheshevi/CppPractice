#include <iostream>

int coinChangedp(int coin[],int total,int sum,int count,int len,int pos);

int main(){
  int coin[] = {2,5,3,6},total = 10;
  int len = sizeof(coin)/sizeof(int);
  std::cout << "Total number of ways is " << coinChangedp(coin,total,0,0,len,0) << std::endl;
  return 0;
}

int coinChangedp(int coin[],int total,int sum,int count,int len,int pos){
  if(total == sum){
    return 1;
  }
  if(sum > total){
    return 0;
  }
  for(int i =pos;i<len;i++){
    // sum+= coin[i];
    count += coinChangedp(coin,total,sum+coin[i],0,len,i);
    // sum -= coin[i];
  }
  return count;
}
