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
int middle(struct node *pt){
  struct node *fast,*slow;
  fast = head;
  slow = head;
  while (fast!=NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow->data;
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

  int res = middle(head);
  cout << res;

  
}