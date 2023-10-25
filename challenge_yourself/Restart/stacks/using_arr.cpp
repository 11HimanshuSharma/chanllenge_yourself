#include<iostream>
using namespace std;

class Stack{
  private:
  int size;
  int top;
  int *Q;
  public:
  Stack(int val){
    size = val;
    top = -1;
    Q = new int[size];
  }
  void push(int val){
    if (top == size-1){
      cout << "Stack is full.";
    }
    else{
      top++;
      Q[top] = val;
    }
  }
  int pop(){
    int x = -1;
    if (top == -1){
      cout << "Stack underflow";
    }
    else{
      x = Q[top--];
    }
    return x;
  }
  bool isEmpty(){
    return top == -1;
  }
  bool isFull(){
    return top == size - 1;
  }
  void print(){
    while (top != -1){
      cout<<"->"<<Q[top--];

    }
  }
};
int main(){
  Stack s(5);
  s.push(20);
  s.push(30);
  s.push(40);

  s.print();
  
}