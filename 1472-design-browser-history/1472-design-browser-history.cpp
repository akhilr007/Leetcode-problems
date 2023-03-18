class Node {
public:
    string val;
    Node* next;
    Node* prev;
    
    Node(string val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* cur;
    BrowserHistory(string homepage) {
        cur = new Node(homepage);
    }
    
    void visit(string url) {
        Node* nn = new Node(url);
        cur->next = nn;
        nn->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {
        
        while(cur->prev && steps > 0){
            cur = cur->prev;
            steps -= 1;
        }
        
        return cur->val;
    }
    
    string forward(int steps) {
        while(cur->next && steps > 0){
            cur = cur->next;
            steps -= 1;
        }
        
        return cur->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */