#include <iostream>
#include <cstdlib>

using namespace std;

bool multipleThree(int num){
	int pos = 0;
	int neg = 0;
	
	if(num < 0)
		num = -num;
	if(num == 0)
		return true;
	if(num == 1)
		return false;

	while(num){
		if(num & 1)
			neg++;
		num = num >> 1;

		if(num & 1)
			pos++;
		num = num >> 1;
	}

	return multipleThree(abs(neg - pos));
}

int main(){
	int num;
	cout<<"Enter the number ";
	cin >> num;
	if(multipleThree(num))
		cout<<"yes, indeed"<<endl;
	else
		cout<<"you can't even find one multiple!!"<<endl;
	return 0;
}