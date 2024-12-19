#include <iostream>
using namespace std;

void swap(int a,int b){
    static int count = 0;
    cout<<"swap called " << ++count << "times."<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swap: a = "  <<a << ", b = "  << b << endl;
}
int main()  {
    int x = 10, y = 20;
    cout << "Before swap:  x = " << x <<", = " << endl;
    swap (x,y);
    cout<<"After swap: x = "  << x <<", = " <<endl;
    return 0;
}