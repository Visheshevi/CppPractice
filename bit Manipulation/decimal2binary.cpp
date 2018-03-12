#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
  string decimal;
  int binary;
  int dec_first = 0;
  double dec_second = 0;
  cout << "Enter the decimal number you want to convert ";
  cin >> decimal;
  int start = 0;
  int end = decimal.length()-1;
  double given = atof(decimal.c_str());
  dec_first = (int)given;
  dec_second = given - dec_first;
  //dec_first = atoi(decimal.substr(start,i).c_str());
  //dec_second = atoi(decimal.substr(i+1,end).c_str());

  if(dec_second == 0 && dec_first == 0){
    cout<< "Binary output is " << 0 << endl;
    return 0;
  }
  int quo = dec_first;
  vector<char> bin_first;
  while(quo>0){
    int temp;
    temp = quo%2;
    bin_first.push_back(temp+'0');
    quo = quo/2;
  }
  reverse(bin_first.begin(),bin_first.end());
  bin_first.push_back('.');
  int p =0;
  while(dec_second>0.0){
    dec_second = dec_second*2;
    int temp = 0;
    temp = (int)dec_second;
    dec_second = dec_second - temp;
    bin_first.push_back(temp+'0');
    if(p>10)
      break;
    p++;
  }
  for(int i = 0;i<bin_first.size();i++)
    cout << bin_first[i];
  cout << endl;
  return 0;
}
