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
  int front;
  int rear;
  Node **Q;
  int size;
  public:
    Queue(int val){
      size = val;
      front = rear = -1;
      Q = new Node*[size];
    }
    void enqueue(Node *p){
      if (rear == size-1){
        cout << "Queue is full.";
      }
      else{
        rear++;
        Q[rear] = p;
      }
    }
    Node *dequeue(){
      Node *temp = NULL;
      if (front == rear){
        cout << "Queue is Null.";
      }
      else{
        front++;
        temp = Q[front];
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
  void prefix(Node *p){
    if (p){
      cout << p->data << " ";
      prefix(p->lchild);
      prefix(p->rchild);
    }
  }
  void postfix(Node *p){
    if (p){
      postfix(p->lchild);
      postfix(p->rchild);
      cout << p->data << " ";
    }
  }
  void infix(Node *p){
    if (p){
      infix(p->lchild);
      cout << p->data << " ";
      infix(p->rchild);
    }
  }
  public:
  Tree(){
    root = NULL;
  }
  void create(){
    int n;
    cout << "Enter the root value: ";
    cin >> n;
    Queue q(10);
    Node *new_node = new Node;
    new_node->data = n;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    root = new_node;
    q.enqueue(root);
    while (!q.isEmpty()){
      int key;
      Node *current_node = q.dequeue();
      cout << "Enter the left child of " << current_node->data << " : ";
      cin >> key;
      if (key!= -1){
        Node *new_node = new Node;
        new_node->data = key;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        current_node->lchild = new_node;
        q.enqueue(new_node);
      }
      cout << "Enter the right child of " << current_node->data << " : ";
      cin >> key;
      if (key != -1){
        Node *new_node = new Node;
        new_node->data = key;
        new_node->lchild = NULL;
        new_node->rchild = NULL;
        current_node->rchild = new_node;
        q.enqueue(new_node);
      }
    }
  }
  void postfix(){
    postfix(root);
  }
  void infix(){
    infix(root);
  }
  void prefix(){
    prefix(root);
  }
  int height(Node *p){
    int l=0;
    int r = 0;
    if (p== NULL){
      return 0;
    }
    l = height(p->lchild);
    r = height(p->rchild);
    if (l>r){
      return l+1;
    }
    else{
      return r+1;
    }
  }
  Node *getroot(){
    return root;
  }
  int countNode(Node *p){
    int x,y;
    while (p){
      x = countNode(p->lchild);
      y = countNode(p->rchild);
      return x+y+1;
    }
    return 0;
  }
  int count(Node *p){
    int x,y;
    if (p){
      x = count(p->lchild);
      y = count(p->rchild);
      return x + y + 1;
    }
    return 0;
  }
};
int main(){
  Tree T;
  T.create();
  cout<<"The tree is: \n";
  T.infix();
  cout<<"\nPostfix traversal:\t\t";T.postfix();
  cout<<"\nInfix traversal:\t\t";T.infix();
  cout<<"\nPrefix traversal:\t\t";T.prefix();
  cout<<"\nHeight of the tree:\t\t"<<T.height(T.getroot())<<endl;
  cout<<"\nNumber of nodes in the tree:\t"<<T.countNode(T.getroot());

  
}