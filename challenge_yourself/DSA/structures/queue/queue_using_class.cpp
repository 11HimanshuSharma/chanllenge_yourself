#include<iostream>
using namespace std;

class Queue{
  private:
  int front;
  int rear;
  int size;
  int *Q;
  public:
  Queue(int s){
    size = s;
  }
  ~Queue(){
    delete[] Q;
  }
  void enqueue(int val);
  void dequeue();
  bool isEmpty();
  void display();
};
void Queue::enqueue(int val){
  if (rear == size - 1){
    cout << "Queue is full." << endl;
  }
  else{
    rear++;
    Q[rear] = val;
  }
}
void Queue::dequeue(){
  if (isEmpty()){
    cout << "Queue is empty" << endl;
  }
  else{
    front++;
  }
}
bool Queue::isEmpty(){
  return (rear == front);
}
void Queue::display(){
  for (int i= front + 1;i<= rear ;i++){
    cout << Q[i] << " ";

  }
}
int Queue::Queue_size(){
  return rear - front + 1;
}
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  Queue q(n+2);
  q.enqueue(50);
  q.enqueue(60);
  q.enqueue(70);
  q.enqueue(80);
  q.enqueue(90);
  q.enqueue(100);
  q.display();
  cout<<endl;
  q.dequeue();
  q.display();
  cout<<endl;
}