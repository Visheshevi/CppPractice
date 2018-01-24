#include <iostream>

using namespace std;

bool powerOFtwo(int num){
	return (num && (!(num & (num -1 ))));
}
int main(){
	int num;
	cout<<"Enter the number ";
	cin >> num;
	cout<<powerOFtwo(num)<<endl;
	return 0;
}