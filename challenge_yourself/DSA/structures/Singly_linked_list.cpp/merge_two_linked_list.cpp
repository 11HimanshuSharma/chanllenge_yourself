#include<iostream>
using namespace std;

struct node {
  int data;
  struct node *next;
}*head1 = NULL,*head2 = NULL,*last1,*last2;

struct node *create(int new_data){
  struct node *new_node;
  new_node = new node;
  new_node->data = new_data;
  new_node->next = NULL;
  return new_node;
}
void display(struct node *pt){
  while (pt!=NULL){
    cout << pt->data << " ";
    pt = pt->next;
  }
}

void merge(struct node *p,struct node *q){
  while (p->next != NULL){
    p = p->next;
  }
  p->next = q;
}


int main(){
  int n1,n2;
  cout << "Please enter the length of list 1:";
  cin >> n1;
  cout << "Plese enter the element of linked list1: ";
  while (n1>0){
    int key;
    cin >> key;
    if (head1==NULL){
      head1 = create(key);
      last1 = head1;
    }
    else{
      struct node *new_node;
      new_node = create(key);
      last1->next = new_node;
      last1 = new_node;
    }
    n1--;
  }
  cout << "Please enter the lenght of linked list2: ";
  cin >> n2;
  cout << "Please enter the element of linked list2: ";
  while (n2>0){
    int key;
    cin >> key;
    if (head2 == NULL){
      head2 = create(key);
      last2 = head2;
    }
    else{
      struct node *new_node;
      new_node = create(key);
      last2->next = new_node;
      last2 = new_node;
    }
    n2--;
  }
  cout << "Linked list 1: ";
  display(head1);
  cout << endl;
  cout << "Linked list 2:";
  display(head2);
  cout << endl;
  cout << "Merged linked list: ";
  merge(head1,head2);
  display(head1);
}