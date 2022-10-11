class MyStack {
private:
    queue<int> q1, q2;
    int s;
public:
    MyStack() {
        s=0;
    }
    
    void push(int x) {
        
        s++;
        q2.push(x);
        
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        if(s==0) return -1;
        s--;
        
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        if(s==0) return -1;
        return q1.front();
    }
    
    bool empty() {
        if(s==0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */