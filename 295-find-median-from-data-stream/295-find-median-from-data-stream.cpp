class MedianFinder {
private:
    priority_queue<int> small; // max_heap
    priority_queue<int, vector<int>, greater<int>> large; // min_heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        //default push will happen at small
        small.push(num);
        
        // check whether every num of small is <= every num of large
        if(small.size() > 0 && large.size() > 0 && small.top() > large.top()){
            int val = small.top(); small.pop();
            large.push(val);
        }
        
        // check for uneven sizes
        if(small.size() > large.size() + 1){
            int val = small.top(); small.pop();
            large.push(val);
        }
        if(large.size() > small.size() + 1){
            int val = large.top(); large.pop();
            small.push(val);
        }
    }
    
    double findMedian() {
        
        if(small.size() > large.size()){
            return (double)small.top();
        }
        if(large.size() > small.size()){
            return (double)large.top();
        }
        
        double ans = (small.top() + large.top())/2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */