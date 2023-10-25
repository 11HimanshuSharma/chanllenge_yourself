#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
}*top = NULL;

void push(int x){
  node *new_node;
  new_node = new node;
  if (new_node == NULL){
    cout << "Stack is FULL\n";
  }
  else{
  new_node->data = x;
  new_node->next = top;
  top = new_node;
  }
}
int pop(){
  int x = -1;
  if (top == NULL){
    cout << "stakc is empty.";
  }
  else{
  node *temp;
  temp = top;
  top = top->next;
  x = temp->data;
  delete temp;}
  return x;
}
void display(){
  node *p;
  p = top;
  while (p!= NULL){
    cout << p->data << " ";
    p = p->next;
  }
  printf("\n");
  
}
int main(){
  push(10);
  push(20);
  push(30);
  display();
}