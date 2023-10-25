#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
};
class LinkedList{
  private:
  Node *tail;
  public:
  LinkedList(){
    tail = NULL;
  }
  void insert(int val){
    Node *new_node = new Node;
    new_node->data = val;
    if (tail== NULL){
      tail = new_node;
      tail->next = tail;
    }
    else{
      new_node->next = tail->next;
      tail->next = new_node;
      tail = new_node;
    }
  }
  void display(){
    Node *temp;
    temp = tail->next;
    do {
      cout << temp->data << " ";
      temp= temp->next;
    }
    while (temp!= tail->next);
  }
};
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  LinkedList L;
  while (n>0){
    int key;
    cin >> key;
    L.insert(key);
    n--;
  }
  L.display();
}