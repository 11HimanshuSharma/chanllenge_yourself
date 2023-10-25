#include<iostream>
using namespace std;
struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};
void create(Queue *q,int n){
  q->size=n;
  q->front = q->rear = -1;
  q->Q = new int[q->size];
}
void enqueue(Queue *q,int val){
  if (q->rear == q->size-1){
    cout << "Queue is full. ";
  }
  else{
    q->rear++;
    q->Q[q->rear] = val;
  }
}
void dequeue(Queue *q){
  if (q->front == q->rear){
    cout << "Queue is empty; ";
  }
  else{
    q->front++;
  }
}
void display(Queue *q){
  for (int i=0;i<=q->rear;i++){
    cout << q->Q[i] << " ";
  }
}
int main(){
  int n;
  cin >> n;
  Queue q;
  create(&q,n);
  while (n>0){
    int key;
    cin >> key;
    enqueue(&q,key);
    n--;
  }
  display(&q);
}