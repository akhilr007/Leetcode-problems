class Node {
    
    public String value;
    public Node next;
    public Node prev;
    
    Node(String value){
        this.value = value;
        this.next = null;
        this.prev = null;
    }
}

class BrowserHistory {
    private Node cur; 
    
    public BrowserHistory(String homepage) {
        cur = new Node(homepage);
    }
    
    public void visit(String url) {
        Node newPage = new Node(url);
        cur.next = newPage;
        newPage.prev = cur;
        cur = cur.next;
    }
    
    public String back(int steps) {
        
        while(cur.prev != null && steps > 0){
            cur = cur.prev;
            steps -= 1;
        }
        
        return cur.value;
    }
    
    public String forward(int steps) {
        while(cur.next != null && steps > 0){
            cur = cur.next;
            steps -= 1;
        }
        
        return cur.value;
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */