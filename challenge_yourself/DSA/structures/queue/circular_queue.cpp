#include<iostream>
using namespace std;

class Queue{
  private:
  int size;
  int front;
  int rear;
  int *Q;
  public:
  Queue(int n){
    size = n;
    Q = new int[size];
    front=rear=-1;
  }
  void enqueue(int val){
    if ((rear+1)%size == front){
      cout << "Queue is full.";
    }
    else{
      rear = (rear+1)%size;
      Q[rear] = val;
    }
  }
  void dequeue(){
    if (rear==front){
      cout << "Queue is full.";
    }
    else{
      front = (front+1)%size;
    }
  }
  void display(){
    for (int i = front + 1;i<= rear;i++){
      cout << Q[i] << " ";
    }
  }
};
int main(){
  int n;
  cout << "Enter any number: ";
  cin >> n;
  Queue Q(n);
  while (n>0){
    int key;
    cin >> key;
    Q.enqueue(key);
    n--;
  }
  Q.display();
}