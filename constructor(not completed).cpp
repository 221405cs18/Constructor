//Name: Asatullaev Fayzulloh

#include <stdio.h>
#include <iostream>
#define MAX_SIZE 5
using namespace std;

class Queue{
    int qfront;
    int qrear;
    int count;
    int maxQueueSize;
    int *q;
public:
    Queue(int size){
        count=0;
        qfront=qrear=-1;
        maxQueueSize=size;
        q = new int[maxQueueSize];
    }
    void enQueue(int num){
            if(qfront == -1 && qrear == -1){
            count++;
            count+=1;
            qfront+=1;
            qrear+=1;
            q[qfront]=num;
        } else if(qrear+1 == MAX_SIZE){
            cout << "queue is full!";
        } else {
            count++;
            count+=1;
            qrear+=1;
            q[qrear]=num;
        }
    }
    void deQueue(){
        if(qfront == -1 && qrear == -1){
            cout << "queue is emty" << endl;
        } else if(qfront == qrear){
            count--;
            qfront=qrear=-1;
        }else {
            count--;
            q[qfront]=0;
            qfront+=1;
        }
    }
    bool isFull(){
        return count == maxQueueSize;
    }
    bool isEmpty(){
        return count == 0;
    }
    int Front(){
        return q[qfront];
    }
    int Back(){
        return q[qrear];
    }
};

int main(int argc, const char * argv[]) {
    Queue q(3);
    q.enQueue(1);
    q.enQueue(10);
    q.enQueue(100);
    q.deQueue();
    q.deQueue();
    q.deQueue();
    
    return 0;
}
