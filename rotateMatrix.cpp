#include <iostream>
#include <algorithm>
using namespace std;


void transpose(int arr[4][4]){
  for (int i=0; i<4; i++)
      for (int j=i; j<4; j++)
          swap(arr[i][j], arr[j][i]);
}
void reverseColumns(int arr[4][4]){
  /* for anti clockwise */
  for (int i=0; i<4; i++)
      for (int j=0,  k=3; j<k; j++,k--)
          swap(arr[j][i], arr[k][i]);
          //swap(arr[j][i],arr[j][k]);
  /* for clockwise */
  for(int i = 0; i < 4; i++) {
    for(int j =0; j < 4/2; j++) {
      swap(arr[i][j], arr[i][4-j-1]);
    }
}
}
int main(){
  int mat[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};


  transpose(mat);
  reverseColumns(mat);
  for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
            cout << mat[i][j] << " ";
        cout<<'\n';
    }

  return 0;
}
