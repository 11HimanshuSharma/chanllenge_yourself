// #include<iostream>
// using namespace std;
// int main(){
//   string name;
//   cin >> name;
//   cout << name;
// }

#include<iostream>
using namespace std;
int main(){
  int arr[2][2] = {{3,4},{3,4}};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout << size;
}