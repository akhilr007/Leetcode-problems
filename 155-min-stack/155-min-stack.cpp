class MinStack {
private:
    stack<int> allData;
    stack<int> minData;
public:
    MinStack() {
       
    }
    
    void push(int val) {
        
        allData.push(val);
        
        if(minData.empty() || val <= minData.top()){
            minData.push(val);
        }
    }
    
    void pop() {
        
        if(allData.empty()) return;
        
        int val = allData.top();
        allData.pop();
        
        if(!minData.empty() && val == minData.top()){
            minData.pop();
        }
    }
    
    int top() {
        if(allData.empty()) return -1;
        
        return allData.top();
    }
    
    int getMin() {
        
        if(minData.empty()) return -1;
        
        return minData.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */