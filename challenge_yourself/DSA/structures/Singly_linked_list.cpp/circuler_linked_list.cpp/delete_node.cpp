#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node *next;
};
class LinkedList{
  private:
  node *tail,*head;
  public:
  LinkedList(){
    tail=NULL;
    head=NULL;
  }
  void push(int val);
  void display();
  void remove(int val);
};
void LinkedList::push(int val){
  node *new_node = new node;
  new_node->data =val;
  if (tail == NULL){
    tail = new_node;
    tail->next = tail;
    head = tail;
  }
  else{
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
  }
}
void LinkedList::display(){
  node *temp = tail->next;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  }while (temp!=tail->next);
}
void LinkedList::remove(int val) {
    if (tail == NULL) {
        cout << "List is empty. Ca";
        return;
    }

    // If the node to be removed is the head node
    if (tail->next->data == val) {
        node* temp = tail->next;
        // If there is only one node in the list
        if (tail->next == tail) {
            tail = NULL;
            head = NULL;
        } else {
            tail->next = tail->next->next;
            head->next = tail->next;
        }
        delete temp;
        cout << "Element " << val << " removed from the list.\n";
        return;
    }

    // Traverse the list to find the node before the node to be removed
    node* temp = tail->next;
    while (temp->next != tail->next && temp->next->data != val) {
        temp = temp->next;
    }

    // If the element was not found in the list
    if (temp->next == tail->next) {
        cout << "Element " << val << " not found in the list.\n";
    } else {
        node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (toDelete == tail) {
            tail = temp; // If the node to be removed is the tail, update the tail pointer
        }
        delete toDelete;
        cout << "Element " << val << " removed from the list.\n";
    }
}

int main(){
  int n;
  cout << "Enter the length of list: ";
  cin >> n;
  LinkedList L;
  while (n>0){
    int key;
    cin >> key;
    n--;
    L.push(key);

  }
  int val;
  cout << "Enter the val need to delete.";
  cin >> val;
  L.remove(val);
  L.display();
}