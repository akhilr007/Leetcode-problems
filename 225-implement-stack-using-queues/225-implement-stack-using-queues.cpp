class MyStack {
private:
    queue<int> q1, q2;
    int cur_size;
public:
    MyStack() {
        cur_size=0;
    }
    
    void push(int x) {
        cur_size++;
        while(q1.size()>0){
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.push(x);
        
        while(q2.size()>0){
            
            q1.push(q2.front());
            q2.pop();
        }
        
    }
    
    int pop() {
        
        cur_size--;
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(cur_size==0){
            return true;
        }
        else{
            return false;
        }
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