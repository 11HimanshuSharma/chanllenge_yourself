#include<iostream>
using namespace std;
// hey buddy you are thinking about recursion that good choice i will help out in figuring solution.
// first int recursion .
// 1. what will common like if are searching an element then the searched element will be same.
// 2. recursion end condition. suppose until when we are doing operation.
// 3. think about tail,head,tree as per problem.
void merge(int arr[],int left,int mid,int right){
  int sizeofone = mid - left + 1;
  int sizeoftwo = right - mid;
  auto *arr_one = new int[sizeofone];
  auto *arr_two = new int[sizeoftwo];
  for (int i=0;i<sizeofone;i++){
    arr_one[i] = arr[left + i];
  }
  for (int i=0;i<sizeoftwo;i++){
    arr_two[i] = arr[mid + 1 + i];
  }
  auto indexofone = 0;
  auto indexoftwo = 0;
  int indexofmerged = left;
  while ((indexofone < sizeofone ) && (indexoftwo < sizeoftwo)){
    if (arr_one[indexofone] < arr_two[indexoftwo]){
      arr[indexofmerged++] = arr_one[indexofone++];
    }
    else{
      arr[indexofmerged++] = arr_two[indexoftwo++];
    }
  }
  while (indexofone < sizeofone){
    arr[indexofmerged++] = arr_one[indexofone++];
  }
  while (indexoftwo < sizeoftwo){
    arr[indexofmerged++] = arr_two[indexoftwo++];
  }
  delete[] arr_one;
  delete[] arr_two;
}
void mergesort(int arr[],int left,int right){
  if (left < right){
    // find mid point of array
    int mid = (right + left)/2;
    // call recursively on two halves
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    // copy data to temp arrays and sort them
    merge(arr,left,mid,right);
    }
  }



int binary_search(int arr[],int size,int key){
  int left = 0;
  int right = size-1;
  while (left <= right){
    int mid = left + (right - left)/2;
    if (arr[mid] == key){
      return mid;
    }
    if (arr[mid] > key){
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }
  return -1;
}
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  mergesort(arr,0,n-1);
  cout << "Sorted Array is : \n";
  for (int i=0;i<n;i++){
    cout << arr[i] << " ";
    }
  cout << "Enter element ro search. ";
  int num;
  cin >> num;
  int pos = binary_search(arr,n,num);
  if (pos != -1) {
    cout << "\nElement found at index "<< pos ;
    } 
    else {
      cout << "\nElement not present in the list" ;
      }
      return 0;

}