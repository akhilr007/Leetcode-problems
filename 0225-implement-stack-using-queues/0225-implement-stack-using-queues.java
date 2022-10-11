class MyStack {
    
    private Queue<Integer> q;
    private int curSize;

    public MyStack() {
        q = new LinkedList<>();
        curSize = 0;
    }
    
    public void push(int x) {
        
        curSize++;
        q.add(x);
        
        int iteration = curSize-1;
        while(iteration-- > 0){
            int val = q.remove();
            q.add(val);
        }
    }
    
    public int pop() {
        
        if(curSize == 0) return -1;
        
        curSize--;
        int val = q.remove();
        return val;
    }
    
    public int top() {
        if(curSize==0) return -1;
        return q.peek();
    }
    
    public boolean empty() {
        if(curSize==0) return true;
        return false;
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */