#include<iostream>
using namespace std;

class Node {
  public:
  int data;
  Node *lchild;
  Node *rchild;
};
class BST{
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
  BST(){
    root = NULL;
  }
  void insert(int val){
    Node *new_node = new Node;
    new_node->data = val;
    new_node->lchild = new_node->rchild = NULL;
    if (root == NULL){
      root = new_node;
    }
    else{
      Node *curr,*pre;
      curr = root;
      pre = NULL;
      while (curr){
        pre = curr;
        if (curr->data > val){
          curr = curr->lchild;
        }
        else if (curr->data < val){
          curr = curr->rchild;
        }
        else{
          return;
        }
      }
      if (pre->data > val){
        pre->lchild = new_node;
      }
      else{
        pre->rchild = new_node;
      }
    }
  }
  void preorder(){
    preorder(root);

  }
};
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  BST T;
  while (n>0){
    int key;
    cin >> key;
    T.insert(key);
    n--;

  }
  T.preorder();
}