#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
}*head= NULL,*last;
struct node * create(int val){
  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;
  new_node->next = NULL;
  return new_node;
}
void display(struct node *pt){
  if (pt!=NULL){
    cout << pt->data << " ";
    display(pt->next);
  }
}
// arr method.
void reverse_arr(struct node *pt){
  int arr[100];
  int i = 0;
  struct node *temp;
  temp = pt;
  while (temp!=NULL){
    arr[i++] = temp->data;
    temp = temp->next;
  }
  i--;
  temp = NULL;
  temp = pt;
  while (temp!= NULL){
    temp->data = arr[i--];
    temp = temp->next;
  }
}
// sliding pointer.
void reverse_pointer(struct node *pt){
  struct node *p,*q,*r;
  p = pt;
  q = NULL;
  r = NULL;
  while ((p != NULL)){
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  head = q;
}
void reverse_recurr(struct node *q,struct node *p){
  if (p!=NULL){
    reverse_recurr(p,p->next);
    p->next = q;
  }
  else{
    head = q;
  }
}
void reverse(strut node *q,struct node *p){
  if (p!=NULL){
    reverse(p,p->next);
    p->next = q;
  }
  else{
    head=q;
  }
}

int main(){
  cout << "Enter the length of linked list: ";
  int n;
  cin >> n;
  while (n>0){
    int k;
    cin >> k;
    if (head == NULL){
      head = create(k);
      last = head;
      
    }
    else{
      struct node *new_node;
      new_node = create(k);
      last->next = new_node;
      last = new_node;
    }
    n--;
  }
  struct node *q;
  q = NULL;
  reverse_recurr(q,head);
  display(head);

  
}