#include<iostream>
using namespace std;


void TOH(int n,int a,int b,int c){
  if (n>0){
    TOH(n-1,a,c,b);
    cout << "move" << a << " to " << c << endl;
    TOH(n-1,b,a,c);
  }
}
int main(){
  int x;
  cout << "Enter any number: ";
  cin >> x;
  TOH(x,1,2,3);
}