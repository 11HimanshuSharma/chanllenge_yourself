#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *lchild;
  Node *rchild;
};
class Queue{
  private:
  int size;
  int front;
  int rear;
  Node **Q;
  public:
  Queue(int s){
    size = s;
    front = rear = -1;
    Q = new Node*[size];
  }
  void enqueue(Node *p){
    if (rear == size - 1){
      cout << "Queue is empty.";
    }
    else{
      rear++;
      Q[rear] = p;
    }
  }
  Node *dequeue(){
    Node *temp = NULL;
    if (front == rear){
      cout << "Queue is empty.";
    } 
    else{
      temp = Q[++front];
    }
    return temp;
  }
  bool isEmpty(){
    return front == rear;
  }
};
class Tree{
  private:
  Node *root;
  void preorder(Node *p){
    if (p){
      cout << p->data << " ";
      preorder(p->lchild);
      preorder(p->rchild);
    }
  }
  public:
  Tree(){
    root = NULL;
  }
  void insert(){
    int n;
    cout << "Enter the number of element: ";
    cin >> n;
    Queue q(n);
    int root1;
    cout << "Enter the root element: ";
    cin >> root1;
    if (root == NULL){
      root = new Node;
      root->data = root1;
      root->lchild = root->rchild = NULL;
    }
    q.enqueue(root);
    while (n>0){
      Node *curr = q.dequeue();
      int key;
      cout << "Enter the lchild of "<< curr->data;
      cin >> key;
      Node *new_node1 = new Node;
      new_node1->data = key;
      new_node1->lchild = new_node1->rchild = NULL;
      curr->lchild = new_node1;
      q.enqueue(new_node1);
      cout << "Enter the rchild of " << curr->data;
      cin >> key;
      Node *new_node2 = new Node;
      new_node2->data = key;
      new_node2->rchild = new_node2->lchild = NULL;
      curr->rchild = new_node2;
      q.enqueue(new_node2);
      n--;
    }
  }
  void preorder(){
    preorder(root);
  }
  int height(Node *root){
    if (!root){
      return;
    }
    int x,y;
    x=height(root->lchild);
    y=height(root->rchild);
    if (x > y) {
      return x+1;
      }
      else{
        return y + 1;
        }
  }
};
int main(){
  Tree t;
  t.insert();
  t.preorder();
}