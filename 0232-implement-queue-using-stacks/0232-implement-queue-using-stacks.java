class MyQueue {
    
    private Stack<Integer> input, output;
    private int size;
    
    public MyQueue() {
        input = new Stack<>();
        output = new Stack<>();
        size = 0;
    }
    
    public void push(int x) {
        size++;
        input.push(x);
    }
    
    public int pop() {
        if(size==0) return -1;
        
        size--;
        
        if(output.size() ==0){
            while(input.size()>0){
                output.push(input.pop());
            }
            
            int val = output.pop();
            return val;
        }
        else{
            int val = output.pop();
            return val;
        }
    }
    
    public int peek() {
        if(size==0) return -1;
        
        if(output.size() ==0){
            while(input.size()>0){
                output.push(input.pop());
            }
            
            return output.peek();
        }
        else{
            return output.peek();
        }
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