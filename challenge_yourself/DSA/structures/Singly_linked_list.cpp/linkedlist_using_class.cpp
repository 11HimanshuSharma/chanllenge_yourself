#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node *next;
};
class LinkedList{
  private:
  node *head;
  public:
  LinkedList(){head = NULL;}
  LinkedList(int arr[],int size);
  ~LinkedList();
  void display();
  void insert(int index,int new_data);
  void remove(int index);
  int length();
  void reverse();
  void reverse_recurr(node *q,node *p);
  
};
LinkedList::LinkedList(int arr[],int size){
  head = new node;
  head->data = *(arr);
  head->next = NULL;
  node *last;
  last = head;
  for (int i=1 ;i <size;i++){
    node *new_node;
    new_node = new node;
    new_node->data = *(arr+i);
    new_node->next = NULL;
    last->next = new_node;
    last = new_node;
  }
}

void LinkedList::insert(int index,int new_data){
  node *q,*p;
  p = head;
  q = NULL;
  while (index > 0){
    q = p;
    p = p->next;
    index--;
  }
  node *new_node;
  new_node = new node;
  new_node->data = new_data;
  new_node->next = q->next;
  q->next = new_node;
}
void LinkedList::reverse_recurr(node *q,node *p){
  if (p!=NULL){
    reverse_recurr(p,p->next);
    p->next  = q;

  }
  else{
    head = q;
  }
}
void LinkedList::remove(int index){
  node *p,*q;
  p = head;
  q = NULL;
  while (index > 0){
    q = p;
    p = p->next;
    index--;
  }
  q->next = p->next;
  node *temp;
  temp = p;
  delete p;
}
LinkedList::~LinkedList(){
  node *p;
  p = head;
  while (head){
    head = head->next;
    delete p;
    p = head;
  }
}
void LinkedList::reverse(){
  node *p,*q,*r;
  p = head;
  q= NULL;
  r = NULL;
  while (p){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}
int LinkedList::length(){
  int count = 0;
  node *p;
  while (p){
    count++;
    p = p->next;
  }
  return count;
}
void LinkedList::display(){
  node *p;
  p = head;
  while (p){
    cout << p->data << " ";
    p = p->next;
  }
}
int main(){
  int n;
  cout << "Please enter the size of linked list: ";
  cin >> n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];
  }
  LinkedList l(arr,n);
  l.insert(1,5);
  l.remove(1);
  l.display();
  int res = l.length();
  cout<<"Length is "<<res<<endl;
  cout << "Reverse LinkedList is: ";
  l.reverse();
  l.display();
}