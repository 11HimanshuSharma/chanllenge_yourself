#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *next;
};
class Queue{
  private:
  Node  *rear;
  Node *front;
  public:
  Queue(){
    front=NULL;
    rear=NULL;
  }
  void enqueue(int val);
  void dequeue();
  void display();
  bool isEmpty();
  bool isFull();
};
void Queue::enqueue(int val){
  Node *new_node = new Node;
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
void Queue::dequeue(){
  if (isEmpty()){
    cout << "queue is empty.";
  }
  else {
    Node *temp = front;
    front = front->next;
    delete temp;}
}
void Queue::display(){
  Node *temp;
  temp = front;
  while (temp != NULL){
    cout << temp->data << " ";
    temp = temp->next;
  }
}
bool Queue::isEmpty(){
  return (rear==NULL && front==NULL);
}
bool Queue::isFull(){
  Node *new_node = new Node;
  if (new_node == NULL){
    return true;  
  }
  delete new_node;
  return false;
  }


int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  Queue q;
  for (int i=0 ;i<n ;i++){
    int num;
    cout << "Enter a number to enqueue :";
    cin >> num;
    q.enqueue(num);
    }
    cout<<"Queue elements are : ";
    q.display();
//     cout<<endl;
//     cout<<"Dequeuing all the numbers from queue : ";
//     for (int j=0 ;j<n ;j++)
// ?
}