//Name: Asatullaev Fayzulloh

#include <iostream>
#include <queue>
using namespace std;

class Queue {
public:
    int qfront;
    int qrear;
    int count;
    int maxQueueSize;
    int *q;
    Queue(int size) {
        count = 0;
        qfront = qrear = -1;
        maxQueueSize = size;
        q = new int[maxQueueSize];
    }
    void enQue(int num){
        if (qfront == -1 && qrear == -1) {
            qfront += 1;
            qrear += 1;
            q[qfront] = num;
            count++;
        } else if (count == maxQueueSize) {
            cout << "Queue is full!" << endl;
        } else {
            qrear = (qrear + 1) % maxQueueSize;
            q[qrear] = num;
            count++;
        }
    }
    
    void displayQue(){
        int i=qfront;
        int c=count;
        while(c){
            c--;
            cout << q[i] << " ";
            i=(i+1)%maxQueueSize;
        }
        cout << endl;
    }
    
    void deQue(){
        if (qfront == -1 && qrear == -1) {
            cout << "Queue is emty!" << endl;
        } else if (qfront == qrear) {
            qrear = qfront = -1;
            count--;
        } else {
            count--;
            q[qfront] = 0;
            qfront = (qfront + 1) % maxQueueSize;
            
        }
    }
    
    bool isFull() {
        return count == 0;
    }
    bool isEmpty() {
        return count == maxQueueSize;
    }
    int front() {
        return q[qfront];
    }
    int back() {
        return q[qrear];
    }
};

int main(int argc, const char * argv[]) {
    Queue q(3);
    q.enQue(10);
    q.displayQue();
    q.enQue(10);
    q.displayQue();
    q.enQue(100);
    q.displayQue();
    q.deQue();
    q.enQue(1);
    q.displayQue();
    
    return 0;
}

