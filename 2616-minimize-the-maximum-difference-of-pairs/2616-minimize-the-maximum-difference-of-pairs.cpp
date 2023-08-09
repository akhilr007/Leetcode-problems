class Solution {
public:
    bool isValid(vector<int>& nums, int p, int diff){
        
        int count=0;
        for(int i=0; i<nums.size()-1;){
            
            int curDiff = abs(nums[i]-nums[i+1]);
            if(curDiff <= diff){
                count++;
                i += 2;
            }
            else{
                i++;
            }
        }
        
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        
        int N = nums.size();
        sort(nums.begin(), nums.end());
        
        int l=0;
        int r=nums[N-1]-nums[0];
        
        int result = r;
        
        while(l <= r){
            
            int mid = l + (r-l)/2;
            
            if(isValid(nums, p, mid)){
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        
        return result;
    }
};