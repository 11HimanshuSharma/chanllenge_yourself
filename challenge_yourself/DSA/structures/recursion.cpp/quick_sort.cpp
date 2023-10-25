#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
  int pivot = arr[high];
  int i = low-1;
  for (int i=low;i<=high;i++){
    if (arr[i] < pivot){
      swap(arr[i],pivot);
    }
  }
  swap(arr[i+1],arr[high]);
  return i+1;
}
void quickSort(int arr[],int left,int right){
  if (left < right){
    int pi = partition(arr,left,right);
    quickSort(arr,left,pi-1);
    quickSort(arr,pi+1,right); 
  }
}
int main(){
  int arr[] = {1,6,8,4,2,5,8,0,4,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Array Before Sorting: ";
  for (int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
  quickSort(arr,0,n-1);
  cout<<"Array After Sorting: ";
  for (int i=0;i<n;i++)
  cout << arr[i] << " ";
  cout << endl;
  return 0;
}