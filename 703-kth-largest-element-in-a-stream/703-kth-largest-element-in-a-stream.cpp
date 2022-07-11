class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i=0; i<nums.size(); i++){
            if(pq.size() < k){
                pq.push(nums[i]);
            }
            else{
                pq.push(nums[i]);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
        if(pq.size() < K){
            pq.push(val);
            return pq.top();
        }
        else{
            pq.push(val);
            pq.pop();
            return pq.top();
        }
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */