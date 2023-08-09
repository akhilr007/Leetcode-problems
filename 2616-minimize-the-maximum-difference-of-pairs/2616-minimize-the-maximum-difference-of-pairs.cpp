class Solution {
public:
    bool isValid(vector<int>& nums, int p, int diff){
        
        int count=0;
        for(int i=0; i<nums.size()-1; ){
            
            int curDiff = abs(nums[i]-nums[i+1]);
            if(curDiff <= diff)
            {
                count++;
                i += 2;
            }
            else
            {
                i += 1;
            }
        }
        
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        sort(begin(nums), end(nums));
        int l=0;
        int r=nums[nums.size()-1]-nums[0];
        
        int result;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            if(isValid(nums, p, mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid +1;
            }
        }
        
        return result;
    }
};