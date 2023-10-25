#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
class linkedlist{
    private:
    node* first;
    node* last;
    public:
    linkedlist(){
        first=NULL;
        last=NULL;
    }
    void create(int x){
        node* temp = new node;
        temp->data=x;
        temp->next=NULL;
        if(first==NULL){
            first = temp;
            last=temp;
        }
        else{
            last->next=temp;
            last=temp;
        }
        }
        void display(){
            node* temp=first;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        void insertAtFirst(int x){
            node* temp=new node;
            temp->data=x;
            temp->next=first;
            first=temp;
        }
    
};

int main(){
    linkedlist l;
    int n;
    cout<<"enter number of node: ";
    cin>>n;
    int m;
    cout<<"enter element: ";
    for(int i=0;i<n;i++){
        cin>>m;
        l.create(m);
    }
    l.display();
    int a;
    cout<<endl<<"enter element to insert: ";
    cin>>a;

    l.display();
}