#include <iostream>

using namespace std;

int nextHeighest(int num){
	unsigned int count = 0;
	if(num && !(num & (num - 1)))
		return num;
	while(num != 0){
		num = num >> 1;
		count++;
	}
	return 1 << count;

}

int main(){
	unsigned int num = 6;
	cout<<nextHeighest(num)<<endl;
	return 0;
}