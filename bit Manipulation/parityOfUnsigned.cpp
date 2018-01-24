#include <iostream>
#include <string.h>
using namespace std;

int findParity(int num){
	int count = 0;
	while(num){
		if(num & 1)
			count++;
		num >>= 1;
	}

	return count;
}

int main()
{
	int num;
	cout<<"enter the number ";
	cin >> num;
	if(findParity(num % 2) == 0)
		cout<<"Even is what we wanted. So satisfying!!"<<endl;
	else
		cout<<"Odd!!! Atleast we can find the middle element now."<<endl;
	return 0;
}