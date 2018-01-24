#include <iostream>

using namespace std;


/* My way */
int sevenMul(int num){
	int sum = 0;
	int i;
	for(i = 0;i<3;i++){
		sum = sum + num;
		num = num<<1;
	}
	return sum;
}

/* Geeks for Geeks way */
/* this is faster than my function */
int geeks(int num){
	return ((num<<3) - num);
}

int main(){
	int num;
	cout<<"Enter the number ";
	cin>>num;
	cout<<"the product is "<<sevenMul(num)<<endl;
	cout<<"the product again is "<<geeks(num)<<endl;
	return 0;

}