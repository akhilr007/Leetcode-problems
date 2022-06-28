class MinStack {
private:
    stack<long long> st;
    long long minEl;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(st.size() == 0){
            st.push(val);
            minEl = val;
        }
        // if the val is greater than min element then min we be same as before so just
        // push the element into stack
        else if(val >= minEl){
            st.push(val);
        }
        // if the val is less than min then we need to store some flag value to stack
        // so that we can identify it later
        // if val < min
        // then stack-> val + val - min and update the min to val
        else{
            st.push(val + (val - minEl));
            minEl = val;
        }
    }
    
    void pop() {
        
        if(st.size() == 0) return;
        
        if(st.top() >= minEl){
            st.pop();
        }
        else{
            // top of stack = value + value - minEl
            // minEl = value 
            // agar top of stack pop kiya to minEl me be previous minEl update karna hoga
            // minEl = 2*value - (value + value - min)
            long long updatedMin = 2*minEl - st.top();
            minEl = updatedMin;
            st.pop();
        }
    }
    
    int top() {
        if(st.size() == 0) return -1;
        
        if(st.top() >= minEl){
            return (int)st.top();
        }
        else{
            // agar top of stack min se small hai to matlab humne top of stack kuch flag
            // store kiya hua h aur real value minEl me hai
            return (int)minEl;
        }
    }
    
    int getMin() {
        if(st.size() == 0) return -1;
        
        return (int)minEl;
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