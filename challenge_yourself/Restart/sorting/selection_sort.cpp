#include<iostream>
#include<algorithm>
using namespace std;

void selection_sort(int arr[],int size){
  for (int i=0;i<size-1;i++){
    int min = i;
    for (int j = i+1;j<size;j++){
      if (arr[j] <arr[min]){
        min = j;
      }
    }
    swap(arr[i],arr[min]);
  }
}
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  selection_sort(arr,n);
  cout<<"Sorted array is :";
  for (int i=0;i<n;i++){
    cout << arr[i] << " ";
    }
}