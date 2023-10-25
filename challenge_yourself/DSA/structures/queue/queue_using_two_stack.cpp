#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
};
class Stack{
  private:
  Node *head;
  public:
  Stack(){
    head = NULL;
  }
  void push(int val);
  void pop();
  bool isEmpty();
  int top();
};
void Stack::push(int val){
  Node *new_node = new Node;
  new_node->data = val;
  new_node->next = NULL;
  if (head == NULL){
    head = new_node;
  }
  else{
    new_node->next = head;
    head = new_node;
  }
}
void Stack::pop(){
  Node *temp;
  temp = head;
  head = head->next;
}
bool Stack::isEmpty(){
  return head == NULL;
}
int Stack::top(){
  return head->data;
}

class Queue{
  private:
  Stack s1,s2;
  public:
  void enqueue(int val);
  void dequeue();
  bool isFull();
  bool isEmpty();
  void display();
};
void Queue::enqueue(int val){
  s1.push(val);
  while (!s1.isEmpty()){
    s2.push(s1.top());
    s1.pop();
  }
}
void Queue::dequeue()
{
  if (s2.isEmpty()){
    if (s1.isEmpty()){
      cout << "Queue is empty.";
    }
    else{
      while (!s1.isEmpty()){
        s2.push(s1.top());
        s1.pop();
      }
    }
    s2.pop();
  }
}
void Queue::display(){
  cout<<"The queue elements are : ";
  while(!s2.isEmpty()) {
    cout << s2.top() << " ";
    s2.pop();
    }
    }


    
int main(){
   Queue q;
  int n;
  cout << "Enter any number: ";
  cin >> n;
 
  while (n>0){
    int x;
    cout << "Enter element to be pushed into the stack: ";
    cin >> x;
    q.enqueue(x);
    n--;
  }
    cout << "\nElements in the queue after pushing all elements:\n";
    q.display();
  
}