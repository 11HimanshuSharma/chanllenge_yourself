#include<iostream>
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

bool isvalid(string s){
  stack st;
  for (int i=0;i<s.size();i++){
    if (s[i] == '(' || s[i] == '{'|| s[i] == '['){
      st.push(s[i]);
    }
    else{
      if (st.isEmpty()){
        return false;
      }
      if (st.topp() == '{' && s[i] == '}'){
        st.pop();
      }
      else if (st.topp() == '(' && s[i] == ')'){
        st.pop();
      }
      else if (st.topp() == '[' && s[i] == ']'){
        st.pop();
      }
      else{
        return false;
      }
    }
  }
  if(st.isEmpty()){
   return true;
  }
  else{
    return false;
  }

}
int main(){
  string s;
  stack st;
  getline(cin,s);
  if (isvalid(s)){
    cout << "This is valid.";
  }
  else{
    cout << "this is Invalid. ";
  }

}

