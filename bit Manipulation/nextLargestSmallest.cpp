#include <iostream>

using namespace std;

int bigger(int num){
  int temp_num = num;
  int i=0,j=0;
  while((temp_num & 1)==0 && temp_num!=0){
    i++;
    temp_num = temp_num>>1;
  }
  while(temp_num & 1 == 1){
    j++;
    temp_num = temp_num >> 1;
  }
  int pos = 0;
  pos = i+j;
  int temp = 1<<pos;
  temp = temp-1;
  temp = ~temp;
  temp_num = num & temp;
  temp_num |= (1<< pos);
  temp = 1<<j-1;
  temp = temp-1;
  temp_num = temp_num + temp;
  return temp_num;
}

int lesser(int num){
  int i=0,j=0;
  int temp_num = num;
  while((temp_num&1)==1){
    temp_num = temp_num >> 1;
    i++;
  }
  while((temp_num & 1)== 0 && (temp_num!= 0)){
    temp_num = temp_num >> 1;
    j++;
  }
  int pos = i+j;
  temp_num = ~0;
  temp_num = temp_num <<(pos+1);
  int temp = temp_num & num;
  temp_num = 1 << (i+1);
  int temp_num2 = temp_num - 1;
  temp_num = temp_num2 << (j-1);
  num = temp | temp_num;
  //temp += 1<<i;
  cout << num << endl;
  //cout << i << " " << j << endl;
  return num;
}
int main(){
  int num;
  cout << "Enter the number ";
  cin >> num;
  int larger = 0, smaller = 0;

  larger = bigger(num);
  smaller = lesser(num);
  //cout << larger << endl;
  //cout << "left is " << j << " and right is " << i << endl;
  return 0;
}
