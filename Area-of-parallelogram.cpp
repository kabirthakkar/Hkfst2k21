#include <iostream>
using namespace std;
  
int main(){
    float base, height, area;
    cout << "Enter the base and height parallelogram\n";
    cin >> base >> height;
     
    // Area of parallelogram = base X height 
    area = base * height;
    cout << "Area of parallelogram : " << area;
      
    return 0;
}

