#include<iostream>
using namespace std;
struct stack{
  int size;
  int top;
  int *s;
};
void push(stack &st,int x){
  if (st.top == st.size-1){cout << "Stack overflow";}
  else {
    st.top++;
    st.s[st.top] = x;
  }
}
void display(stack st){
  while (st.top != -1){
    cout << st.s[st.top] << " ";
    st.top--;
  }
}
int pop(stack &st){
  int x;
  if (st.top == -1){
    cout << "stack underflow";
  }
  else{
    x = st.s[st.top];
    st.top--;
  }
  return x;
}
bool isempty(stack st){
  if (st.top == -1){
    return true;
  }
  return false;
}

void peek(stack st,int index){
  int x  = -1;
  if (st.top-index +1 < 0){
    cout << "Invalid index. ";
  }
  x = st.s[st.top + index + 1];
  cout << "The value at " << index << " is " << x << endl;
}

int top(stack st){
  if (!isempty(st)){
    return st.s[s.top];
  }
  return -1;
}
int main(){
  int n;
  cout << "Enter the size of stack: ";
  cin >> n;
  stack st;
  st.size = n;
  st.top = -1;
  st.s = new int[st.size];
  if (st.s == NULL){
    cout << "Memory allocation is failed. ";
  }
  // st.s = (int *)malloc(st.size*(sizeof(int)));
  while (n > 0){
    int key;
    cin >> key;
    push(st,key);
    n--;
  }
  if (isempty(st)){
    cout << "stack is empty: ";
  }
  else{
    display(st);
  }
  

}