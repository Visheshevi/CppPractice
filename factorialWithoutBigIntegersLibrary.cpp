/*Program to find the factorial of a number and print it*/

/*Can't use the BigIntegers Library. */



#include<iostream>

using namespace std;

void extraLongFactorials(int n) {
    int answer[100];
    answer[0] = 1;
    int len = 1;
    for(int i = 2;i<= n;i++){
        int carry = 0;
        for(int j = 0;j<len;j++){
            int temp = i*answer[j] + carry;
            int digit = temp % 10;
            answer[j] = digit;
            carry = temp/10;
        }
        while(carry){
            len++;
            int temp = carry % 10;
            answer[len-1] = temp;
            carry = carry / 10;
        }        
    }
    for(int i = len-1;i>=0;i--){
        cout<<answer[i];
    }
    
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
