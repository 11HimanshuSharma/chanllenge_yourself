#include<iostream>
using namespace std;

struct stack{
  int top;
  int size;
  int *s;
};
void push(stack &st,int key){
  if (st.top == st.size - 1){
    cout << "stack overflow";
    return;
  }
  else{
    st.top++;
    st.s[st.top] = key;
  }

}
void display(stack st){
  if (st.top == -1){
    cout << "stack underflow";
  }
  while (st.top != -1){
    cout << st.s[st.top]  << " ";
    st.top--;
  }
}
int pop(stack &st){
  int x;
  if (st.top == -1){
    cout << "stack underflow. ";
    
  }
  else{
    x = st.s[st.top];
    st.top--;
  }
  return x;
}
bool isEmpty(stack st){
  return st.top == -1;
}
void peek(stack st,int index){
  int x = -1;
  if (st.top-index + 1 < 0){
    cout << "Invalid index. ";
  }
  x = st.s[st.top-index + 1];
  cout << "THe value at " << index << " is " << x; 
}
int main(){
  int n;
  cout << "Enter the size of stack: ";
  cin >> n;
  stack st;
  st.top = -1;
  st.size = n;
  // st.s = (int *)malloc(sizeof(int)*(st.size));
  st.s = new int[st.size];
  while (n>0){
    int key;
    cin >> key;
    push(st,key);
    n--;
  }
  int index;
  cout << "Please enter the index that you want to find: ";
  cin >> index;
  peek(st,index);
  cout << endl;
  int res;
  res = pop(st);
  cout << "The poped value is: " << res;
  return 0;

}