class MyQueue {
    
    private Stack<Integer> s1, s2;
    private int size;
    
    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
        size = 0;
    }
    
    public void push(int x) {
        size++;
        while(s1.size()>0){
            s2.push(s1.pop());
        }
        
        s1.push(x);
        
        while(s2.size()>0){
            s1.push(s2.pop());
        }
    }
    
    public int pop() {
        if(size==0) return -1;
        
        size--;
        int val = s1.pop();
        return val;
    }
    
    public int peek() {
        if(size==0) return -1;
        
        return s1.peek();
    }
    
    public boolean empty() {
        if(size==0) return true;
        return false;
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */