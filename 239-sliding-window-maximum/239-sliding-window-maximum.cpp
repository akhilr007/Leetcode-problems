class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> d;
        
        int i=0, j=0;
        
        vector<int> res;
        
        while(j< nums.size()){
            
            while(d.size() > 0 && d.back() < nums[j]){
                d.pop_back();
            }
            
            d.push_back(nums[j]);
            
            if(j-i+1<k) j++;
            
            else if(j-i+1 == k){
                
                res.push_back(d.front());
                
                if(nums[i] == d.front()){
                    d.pop_front();
                }
                
                i++;
                j++;
            }
        }
        
        return res;
    }
};