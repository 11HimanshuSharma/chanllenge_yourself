#include<iostream>
using namespace std;

bool check(int arr[],int n){
  for (int i=0;i<n-1;i++){
    if (arr[i] > arr[i+1]){
      return false;
    }
  }
  return true;
}
int main(){
  int arr[] = {1,2,3,5,5,6};
  cout<<check(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
}