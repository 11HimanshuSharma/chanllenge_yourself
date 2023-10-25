#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
};
class stack{
  private:
  node *top;
  public:
  stack(){top = NULL;}
  void push(int x);
  int pop();
  void display();
};
void stack::push(int x){
  node *new_node;
  new_node = new node;
  if (new_node == NULL){
    cout << "stack overflow.";
  }
  else{
    new_node->data = x;
    new_node->next = top;
    top = new_node;

  }
}
int stack::pop(){
  int x = -1;
  if (top == NULL){
    cout << "stack is empty.";
    
  }
  else{
    x = top->data;
    node *temp;
    temp = top;
    top = top->next;
    delete temp;

  }
  return x;
}
void stack::display(){
  node *p;
  p = top;
  while (p!=NULL){
    cout << p->data << " ";
    p = p->next;
  }
}
int main(){
  stack st;
  st.push(10);
  st.push(40);
  st.push(43);
  st.display();
  return 0;
}