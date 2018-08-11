#include <iostream>
#include <vector>

bool isValid(int flower, int k, int length,char* memo){
  memo[flower] = true;
  if(flower+k+1 <= length && memo[flower+k+1]){
    bool valid = true;
    for(int i = 1;i<= k;i++){
      if(memo[flower+i]){
        valid = false;
        break;
      }
    }
    if(valid)
      return true;

  }
  if(flower-k-1 > 0 && memo[flower - k-1]){
    for(int i = 1;i<=k;i++){
      if(memo[flower - i]){
        return false;
      }
    }
    return true;
  }
  return false;
}


int kEmptySlots(std::vector<int>& flowers,int k){
  int length = flowers.size();
  if(k >= length || length == 0){
    return -1;
  }

  std::unique_ptr<char[]> memo(new char[length+1]);
  memset(memo.get(),0,(length+1)*sizeof(char));
  // std::vector<bool> memo;
  //
  // for(int i = 0;i<=length;i++){
  //   // std::cout << "Vishesh" << std::endl;
  //   memo.push_back(false);
  // }
  for(int i = 0;i< length;i++){
    if(isValid(flowers[i],k,length,memo.get()))
      return i+1;
  }
  return -1;
}



int main(){
  std::vector<int> flowers;
  int k = 1;
  flowers.push_back(3);
  flowers.push_back(1);
  flowers.push_back(5);
  flowers.push_back(4);
  flowers.push_back(2);
  std::cout << kEmptySlots(flowers,k) << std::endl;
  return 0;
}
