class MyCircularQueue {
public:
    int *a;
    int N;
    int front, rear;
    MyCircularQueue(int k) {
        a = new int[k];
        N = k;
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        
        if(isFull()) return false;
        
        if(front == -1) front = 0;
        
        rear = (rear + 1) % N;
        a[rear] = value;
        return true;
    }
    
    bool deQueue() {
        
        if(front == -1) return false;
        
        int result = a[front];
        
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % N;
        }
        
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return a[front];
    }
    
    int Rear() {
        if(rear == -1) return -1;
        return a[rear];
    }
    
    bool isEmpty() {
        
        if(front == -1 and rear == -1) return true;
        return false;
    }
    
    bool isFull() {
        
        if((rear+1)%N == front) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */