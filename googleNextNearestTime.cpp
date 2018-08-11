``#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <sstream>


int convertToInt(std::string sTime);
void permute(std::string sDigit, std::vector<int>& ivPermute);
void convertToUseable(std::string& sTime);
std::string Play(std::string sTime,std::vector<int> ivPermute);
std::string convertToString(int iTime);


int main(){
  std::string sTime;
  std::cout << "Enter the time in HH:MM format " << std::endl;
  std::cin >> sTime;
  convertToUseable(sTime);
  std::vector<int> ivPermute;
  permute(sTime,ivPermute);
  // for(int i = 0;i<ivPermute.size();i++){
  //   std::cout << ivPermute[i] << std::endl;
  // }
  std::cout << Play(sTime,ivPermute) << std::endl;
  return 0;
}

int convertToInt(std::string sTime){
  int iNumber = 0;
  for(int i =0;i<sTime.length();i++){
    if(sTime[i] != ':'){
      int iTemp = sTime[i] - '0';
      iNumber = iNumber*10 + iTemp;
    }
  }
  return iNumber;
}

void permute(std::string sDigit, std::vector<int>& ivPermute){
  std::sort(sDigit.begin(), sDigit.end());
    do {
      int iTemp = std::stoi(sDigit);
      int hundreds = iTemp%100;
      // int tens = iTemp%10;
      if(iTemp <= 2359 && iTemp >= 0 && hundreds <60){
        ivPermute.push_back(iTemp);
      }
    } while (std::next_permutation(sDigit.begin(), sDigit.end()));
}

void convertToUseable(std::string& sTime){
  std::string sTemp = "";
  for(int i =0;i<sTime.length();i++){
    if(sTime[i] != ':'){
      sTemp += sTime[i];
    }
  }
  sTime = sTemp;
}

std::string Play(std::string sTime,std::vector<int> ivPermute){
  if(sTime == "0000"){
    return "00:00";
  }
  int isPositive = -1,isNegative = 1;
  int iNeg = 0,iPos = 0;
  int iTempTime = std::stoi(sTime);
  for(auto element:ivPermute){
    int iTemp = element - convertToInt(sTime);
    if(iTemp < 0 && isNegative > 0){
      isNegative = iTemp;
      iNeg = element;
    }
    else if(iTemp > 0 && isPositive < 0){
      isPositive = iTemp;
      iPos = element;
    }
  }
  if(isPositive > 0){
    return convertToString(iPos);
  }
  else if(isNegative < 0){
    return convertToString(iNeg);
  }
  else{
    return convertToString(std::stoi(sTime));
  }
}

std::string convertToString(int iTime){
  std::string sTemp = "";
  int count = 0;
  while(iTime>0){
    int iNum = iTime%10;
    iTime /= 10;
    sTemp += std::to_string(iNum);
    count++;
    if(count == 2){
      sTemp += ':';
    }
  }
  reverse(sTemp.begin(),sTemp.end());
  if(sTemp.length() == 1){
    sTemp.insert(0,"00:0");
  }
  else if(sTemp.length() == 2){
    sTemp.insert(0,"00:");
  }
  else if(sTemp.length() == 3){
    sTemp.insert(0,"00");
  }
  else if(sTemp.length() == 4){
    sTemp.insert(0,"0");
  }
  return sTemp;
}
