#include<iostream>
using namespace std;
struct Node{
  int data;
  struct Node *next;
}*front = NULL,*rear=NULL;

void enqueue(int val){
  struct Node *new_node = new Node;
  new_node->data = val;
  new_node->next = NULL;
  if (front == NULL){
    front = new_node;
    rear = new_node;
  }
  else{
    rear->next = new_node;
    rear = new_node;
  }
}
void dequeue(){
  if (front == rear){
    cout<<"Queue is empty\n";
  }
  else {
    Node *temp;
    temp = front;
    front = front->next;
    delete temp;
  }
}
void display(){
  Node *ptr;
  ptr = front;
  while(ptr != NULL){
    cout << ptr->data << " ";
    ptr = ptr->next;
    }
}
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  while (n>0){
    int key;
    cin >> key;
    enqueue(key);
    n--;
  }
  dequeue();
  display();
}

