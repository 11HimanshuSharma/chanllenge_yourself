#include<iostream>
using namespace std;

int max(int arr[],int size){
  int max = arr[0];
  for (int i=0;i<size;i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}
int main(){
  int n;
  cout << "Enter any NUmber: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  cout<<"Maximum element in the array is : "<<max(arr,n);
  return 0;
}
