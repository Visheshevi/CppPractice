#include <iostream>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int hours=0,minutes=0,seconds=0;
void displayClock(){
  system("clear");
  cout << setfill('-') << setw(50) << "         Timer          " <<  endl<<endl;
  cout << setfill(' ') << setw(2) << hours << "hours\t";
  cout << setw(2) << minutes << "minutes\t";
  cout << setw(2) << seconds << "seconds\t";
  cout << endl << endl;

}

void timer(){
  while(true){
    displayClock();
    Sleep(1000);
    seconds++;
    if(seconds == 60){
      minutes++;
      if(minutes == 60){
        hours++;
        minutes = 0;
      }
      seconds = 0;
    }
  }
}

int main(){

  timer();
  return 0;
}
