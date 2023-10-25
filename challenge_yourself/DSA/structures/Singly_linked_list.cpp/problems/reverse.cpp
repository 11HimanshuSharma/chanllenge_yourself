#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *next;
};
class LinkedList{
  public:
  Node *head,*last;
  public:
  LinkedList(){
    head = NULL;
    last = NULL;
  }
  void insert(int val){
    if (head== NULL){
      head = new Node;
      head->data = val;
      last = head;
    }
    else{
      Node *new_node = new Node;
      new_node->data = val;
      new_node->next = NULL;
      last->next = new_node;
      last = new_node;
    }
  }
};
Node *reverse(Node *first,Node *last){
  Node *p,*q,*r;
  p = first;
  q = NULL;
  r = NULL;
  Node *temp = last->next;
  while (p != temp){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
    }
    
    return q; 
}

void revl(Node *head,int first,int last){
  Node *p,*q,*f,*r;
  f = head;
  q = head;
  while (first>0){
    p = f;
    f=f->next;
  }
  while (last >0){
    r = q;
    q=q->next;
  }
  reverse(f,r);


}
int main(){
  int n;
  cout << "Please enter any number: ";
  cin >> n;
  LinkedList l;
  for (int i=1 ;i<=n;i++){
    int key;
    cin >> key;
    l.insert(i);
    }
  
    Node *temp = l.head;
    revl(l.head,2,4);
    cout<<"Reversed linked list is :";
    while (temp!=NULL) {
      cout << temp->data << " ";
      temp = temp->next;
      }
}