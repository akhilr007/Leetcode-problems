class MyStack {
    
    private Queue<Integer> q1, q2;
    private int curSize;

    public MyStack() {
        q1 = new LinkedList<>();
        q2 = new LinkedList<>();
        curSize = 0;
    }
    
    public void push(int x) {
        
        curSize++;
        while(q1.size()>0){
            q2.add(q1.remove());
        }
        
        q1.add(x);
        
        while(q2.size()>0){
            q1.add(q2.remove());
        }
    }
    
    public int pop() {
        
        if(curSize == 0) return -1;
        
        curSize--;
        int val = q1.remove();
        return val;
    }
    
    public int top() {
        if(curSize==0) return -1;
        return q1.peek();
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