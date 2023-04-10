//Name: Asatullaev Fayzulloh

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
};
class Queue{
private:
    Node *qfront;
    Node *qrear;
public:
    Queue(){
        qfront=qrear=NULL;
    }
    void enqueue(int n){
        Node *newnode = new Node();
        newnode->value=n;
        newnode->next=nullptr;
        if(qfront == NULL && qrear == NULL){
        qfront=qrear=newnode;
        } else {
            qrear->next=newnode;
            qrear=newnode;
        }
    }
    void dequeue(){
        Node *del = qfront;
        qfront=qfront->next;
        delete del;
        if(qfront == NULL){
            qrear=NULL;
        }
    }
    bool isEmpty(){
        return (qrear == NULL);
    }
    int size(){
        Node *temp=qfront;
        int size=0;
        while(temp != NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }
    void displayQueue(){
        Node* temp=qfront;
        while(temp != NULL){
            cout << temp->value << " ";
            temp=temp->next;
        }
    }
    int front(){
        return qfront->value;
    }
    int back(){
        return qrear->value;
    }
};

int main(){
    Queue q;
    q.enqueue(5);
    q.displayQueue();
    cout << endl;
    q.enqueue(50);
    q.displayQueue();
    cout << endl;
    q.enqueue(500);
    q.displayQueue();
    cout << endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;
    q.dequeue();
    q.displayQueue();
    cout << endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;
    q.enqueue(100);
    q.displayQueue();
    cout << endl;
    q.dequeue();
    cout<<q.front()<<" "<<q.back()<<endl;
    q.dequeue();
    q.displayQueue();
    cout << endl;
    q.dequeue();
    cout<<q.isEmpty()<<endl;
    cout<<q.size()<<endl;
    
    return 0;
}
