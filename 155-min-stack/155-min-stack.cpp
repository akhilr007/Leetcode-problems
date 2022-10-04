class MinStack {
    
    private Stack<Integer> st;
    private Stack<Integer> mini;
    
    public MinStack() {
        st = new Stack<>();
        mini = new Stack<>();
    }
    
    public void push(int val) {
        
        st.push(val);
        
        if(mini.size() == 0){
            mini.push(val);
        }
        else{
            if(val <= mini.peek()) mini.push(val);
        }
    }
    
    public void pop() {
        
        int minEl = mini.peek();
        
        if(minEl == st.peek()){
            st.pop();
            mini.pop();
        }
        else st.pop();
    }
    
    public int top() {
        
        if(st.size() == 0) return -1;
        return st.peek();
    }
    
    public int getMin() {
        if(mini.size() == 0) return -1;
        return mini.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */