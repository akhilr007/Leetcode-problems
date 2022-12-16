class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        if(st1.size()>0){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        
        st1.push(x);
        
        while(!st2.empty()){
            
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        
        int val = -1;
        if(st1.size()>0){
            val = st1.top();
            st1.pop();
        }
        
        return val;
    }
    
    int peek() {
        
        if(st1.size() > 0) return st1.top();
        return -1;
    }
    
    bool empty() {
        
        if(st1.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */