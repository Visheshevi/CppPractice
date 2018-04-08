#include <iostream>
#include <vector>
using namespace std;

struct Point{
  int x;
  int y;
};


int orientation(Point p1,Point p2, Point p3){
  int val = (p2.y - p1.y) * (p3.x - p2.x) -  (p2.x - p1.x) * (p3.y - p2.y);
  if(val == 0)
    return 0;
  return (val>0)?1:-1;
}

void convexHull(Point p[],int n){
  vector<Point> result;
  if(n<3){
    cout << "na ho payega" << endl;
    return;
  }
  int left = 0;
  for(int i =1;i<n;i++)
    if(p[i].x < p[left].x)
      left = i;

  int next = left,temp;

  do{
    result.push_back(p[next]);

    temp = (next+1)%n;

    for(int i = 0;i<n;i++){
      if(orientation(p[next],p[i],p[temp]) == -1)
        temp = i;
    }

    next = temp;
  }while(left != next);

  for(int i =0;i<result.size();i++){
    cout << result[i].x << " " << result[i].y <<endl;
  }
}
int main(){
  Point p[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
  int n  = sizeof(p)/sizeof(p[0]);
    //int n = sizeof(points)/sizeof(points[0]);
    convexHull(p,n);
    return 0;
}
