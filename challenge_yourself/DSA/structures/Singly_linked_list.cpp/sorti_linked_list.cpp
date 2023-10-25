#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
};

node *create(int new_data){
  node *new_node;
  new_node = new node;
  new_node->data = new_data;
  new_node->next = NULL;
  return new_node;
}

void display(node *pt){
  while (pt!=NULL){
    cout << pt->data << " ";
    pt = pt->next;
  }
}

node *getmid(node *pt){
  node *slow, *fast;
  slow = pt;
  fast = pt;
  while (fast->next != NULL && fast->next->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

node *merge(node *left, node *right){
  node *merged_node = new node;
  merged_node->next = NULL;
  node *last = merged_node;
  while (left != NULL && right != NULL){
    if (left->data <= right->data){
      last->next = left;
      left = left->next;
    }
    else{
      last->next = right;
      right = right->next;
    }
    last = last->next;
  }
  if (left != NULL){
    last->next = left;
    left = left->next;
  }
  if (right != NULL){
    last->next = right;
    right = right->next;
  }
  return merged_node->next;
}

node* mergesort(node* p) {
  if (p == NULL || p->next == NULL) {
    return p;
  }

  node* mid_node = getmid(p);
  node* right_node = mid_node->next;
  mid_node->next = NULL;

  node* left = mergesort(p);
  node* right = mergesort(right_node);

  return merge(left, right);
}

int main(){
  int n;
  cout << "Enter the size of linked list: ";
  cin >> n;
  struct node *head,*last;
  head = NULL;
  last = NULL;
  while (n>0){
    int key;
    cin >> key;
    if (head == NULL){
      head = new node;
      head->data = key;
      head->next = NULL;
      last = head;
    }
    else{
      node *new_node;
      new_node = create(key);
      last->next = new_node;
      last = new_node;
    }
    n--;
  }
  cout << "Linked list: ";
  display(head);
  cout << endl;
  node *new_node;
  new_node = mergesort(head);
  cout << "Sorted linked list: ";
  display(new_node);
}
