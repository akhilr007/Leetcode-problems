class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int capacity;
public:
    KthLargest(int k, vector<int>& nums) {
        
        capacity = k;
        
        for(auto el : nums){
            pq.push(el);
            if(pq.size()>capacity) pq.pop();
        }
    }
    
    int add(int val) {
        
        pq.push(val);
        if(pq.size()>capacity) pq.pop();
        
        return pq.top();
    }
};
