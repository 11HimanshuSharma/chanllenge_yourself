#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
};
class LinkedList{
  private:
  node *last;
  public:
  LinkedList(){last = NULL;}
  void insert(int val);
  void display();
  void remove(int val);
};
void LinkedList::insert(int val){
  node *new_node = new node;
  new_node->data = val;
  if (last == NULL){
    last = new_node;
    last->next = last;
  }
  else {
    new_node->next = last->next;
    last->next = new_node;
    last = new_node;
  }
}
void LinkedList::display(){
  node *temp = last->next;
  do{
    cout << temp->data << " ";
    temp = temp->next;
  }
  while (temp!=last->next);
}
void LinkedList::remove(int val){
  node *head = last->next;
  if (last->next->data == val){
    node *temp;
    temp = last->next;
    last->next = temp->next;
    delete temp;
  }
  while (last!= last->next && last->next->data != val){
    last = last->next;
  }
  node *temp;
  temp = last->next;
  last->next = temp->next;
  delete temp;
  while (last!= last->next){
    last = last->next;
  }

}
int main(){
  int n;
  cout << "Enter the number: ";
  cin >> n;
  LinkedList L;
  while (n>0){
    int key;
    cin >> key;
    L.insert(key);
    n--;
    
  }
  L.remove(3);
  L.display();
}