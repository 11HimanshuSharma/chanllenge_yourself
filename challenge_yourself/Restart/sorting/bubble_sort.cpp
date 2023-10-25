#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort(int arr[],int size){
  for (int i=1;i<size;i++){
    int did_swap = 0;
    for (int j=0;j<size-1;j++){
      if (arr[j] > arr[j+1]){
        swap(arr[j],arr[j+1]);
        did_swap = 1;
      }
    }
    if (did_swap == 0){// if we found any iteration that in which no swping id done then we can say arr is sorted
      break;
    }
  }

}
int main(){
  int n;
  cout << "Enter size of arr: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  //bubble sort algorithm
  bubble_sort(arr,n);
  cout << "Sorted arr: ";
  for (int i=0;i<n;i++){
    cout << arr[i]<<" ";
    }
  
}