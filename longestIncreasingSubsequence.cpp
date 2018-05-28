#include<iostream>

using namespace std;

int max(int f,int s){
  return (f>s)?f:s;
}
int lis(int *input, int count,int prev,int pos,int length){

  if(pos == length){
    return count;
  }
  if(input[pos]>prev){
    return lis(input,count+1,input[pos],pos+1,length);
  }
  else{
    return max(lis(input,count,prev,pos+1,length),lis(input,1,input[pos],pos+1,length));
  }
  return count;
}

int main(){
  int input[] = {1,2,1,7};
  int length = sizeof(input)/sizeof(int);
  cout << lis(input,0,-1,0,length) << endl;
  return 0;
}
