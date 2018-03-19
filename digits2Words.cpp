#include <iostream>
#include <string>

using namespace std;

string singles[10] = {"","one","two","three","four","five","six","seven","eight","nine"};
string teens[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string doubles[10] = {"","","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
string biggies[3] = {" hundred "," thousand "," million "};

string basics(string final_result,int num){
  final_result = "";
  if(num == 0 ){
    final_result = "";
  }
  else if(num >0  && num <10){
    final_result = singles[num];
  }
  else if(num > 9  && num  < 20){
    final_result = teens[num -10];
  }
  else if(num > 19 && num < 100){
    int temp = num;
    final_result = final_result+singles[temp%10];
    temp = temp/10;
    final_result = doubles[temp] + " " + final_result;
  }
  return final_result;
}

string amateurs(string final_result,int num){
  string temp = "";
  if(num > 100){
    temp = basics(temp,num%100);
    return singles[num/100] + biggies[0] + temp;
  }
  else{
    return basics(temp,num%100);
  }
}

string intermediate(string final_result,int num){
  final_result = "";
  final_result = amateurs(final_result,num%1000);
  num = num/1000;
  if(num<100){
    final_result = basics(final_result,num) + biggies[1] + final_result;
  }
  else
    final_result = amateurs(final_result,num) + biggies[1] + final_result;

  return final_result;
}


int main(){
  long int num;
  cout << "Enter the given number ";
  cin >> num;
  string result = "";
  if(num == 0){
    result = "zero";
  }
  else if(num < 100){
    result = basics(result,num);
  }
  else if(num > 99 && num < 1000){
    result = amateurs(result,num);
  }
  else if(num > 999 && num < 1000000){
    result = intermediate(result,num);
  }

  cout << result << endl;
  return 0;
}
