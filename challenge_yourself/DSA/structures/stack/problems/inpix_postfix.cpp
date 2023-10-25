#include<iostream>
#include<string>
using namespace std;

class node{
  public:
  char data;
  node *next;
};
class stack{
  private:
  node *top;
  public:
  stack(){
    top = NULL;
  }
  void push(char x);
  void pop();
  void display();
  char topp();
  bool isEmpty();
};

void stack::push(char x){
  node *new_node = new node;
  if (new_node == NULL){
    cout << "Stack Overflow";
  }
  else{
    new_node->data = x;
    new_node->next = top;
    top = new_node;
  }

}
void stack::pop(){
  
  if (top == NULL){
    cout << "stack is empty. ";
  }
  else{
    node *temp;
    temp = top;
    top = top->next;
    delete temp;
  }
}
char stack::topp(){
  if (top == NULL){
    return 'E';
  }
  else{
    return top->data;
  }
}
bool stack::isEmpty(){
  return (top== NULL);
}
void stack::display(){
  node *p;
  p = top;
  while (p){
    cout << p->data;
    p = p->next;
  }
}
int pre(char x){
  if (x=='+' || x=='-'){
    return 1;
  }
  else if ((x =='*') || (x == '/')){
    return 2;
  }
  return 0;
}
int isOperand(char x){
  if (x== '+' || x == '-' || x == '*' || x=='/'){
    return 0;
  }
  else{
    return 1;
  }
}
string InTOPost(string s){
  stack stk;
  string st;
  st = " ";
  int n = s.size();
  int i=0;
  while (s[i] != '\0'){
    if (isOperand(s[i])){
      st += s[i++];
    }
    else{
      if (pre(s[i])>pre(stk.topp())){
        stk.push(s[i++]);
      }
      else {
        char temp = stk.topp();
        st+=temp;
        stk.pop();
    }

  }}
  while(!stk.isEmpty()){
    st+=stk.topp();
    stk.pop();
  }
  return st;
}
int main(){
  string s;
  cin >> s;
  cout << "Infix to Postfix: ";
  cout<<InTOPost(s);
  return 0;
}