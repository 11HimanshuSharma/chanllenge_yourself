#include<iostream>
using namespace std;

class node{
  public:
  char data;
  node *next;
};
class Stack{
  private:
  node *head;
  public:
  Stack(){
    head=NULL;
  }
  void push(char val);
  void display();
  bool isEmpty();
  char top();
  void pop();
};
void Stack::push(char val){
  node *new_node = new node;
  if (new_node == NULL){
    cout << "Stack is full. ";
  }
  else{
    new_node->data = val;
    new_node->next = head;
    head = new_node;
  }
}
void Stack::pop(){
  if (head == NULL){
    cout << "Stack is Underflow.";
  }
  else{
    node *temp;
    temp = head;
    head = head->next;
    delete temp;
  }
}
void Stack::display(){
  node *temp;
  temp = head;
  while (temp){
    cout << temp->data << " ";
    temp = temp->next;
  }
}
bool Stack::isEmpty(){
  return (head == NULL);
}
char Stack::top(){
  return head->data;
}
int pre(char x){
  if (x=='+' || x=='-'){
    return 1;
  }
  else if (x=='/' || x=='*'){
    return 2;
  }
  return 0;
}
bool isOperand(char x){
  if (x=='+' || x=='-' || x=='/' || x== '*'){
    return false;
  }
  return true;
}
string convert(string s){
  string st;
  st ="";
  Stack stk;
  int i=0;
  int j=0;
  while (s[i]!= '\0'){
    if (isOperand(s[i])){
      st += s[i++];
    }
    else{
      if (pre(s[i])>pre(stk.top())){
        stk.push(s[i]);
      }
      else{
        st+=stk.top();
        stk.pop();
      }
    }
  }
  while (!stk.isEmpty()){
    st+=stk.top();
    stk.top();
  }
}
int eval(string s){
  Stack st;
  int x1,x2,res;
  for (int i=0;i<s.size();i++){
    if (isOperand(s[i])){
      st.push(s[i]-'0');
    }
    else{
      x1 = st.top();
      st.pop();
      x2 = st.top();
      st.pop();
      switch (s[i]){
        case '+': res = x1 + x2;break;
        case '-': res = x1 - x2;break;
        case '*': res = x1 * x2;break;
        case '/': res = x1 / x2;break;
      }
      st.push(res);
    }
  }
  return st.top();
}

int main() {
  string s;
  cin >> s;
  Stack st;
  for (int i=0;i<s.size();i++){
    st.push(s[i]);
  }
  int res = eval(s);
  cout << "The result of the expression: "<< s <<" is :"<< res<<endl;
}