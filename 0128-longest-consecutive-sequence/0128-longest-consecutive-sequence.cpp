class Solution {
public:
    int find(vector<int>& nums, int num){
        
        for(auto &it : nums){
            if(num == it)
                return true;
        }
        
        return false;
    }
    
    int brute(vector<int>& nums){
        
        int n = nums.size();
        if(n == 0)
            return 0;
        
        int longest = 1;
        for(int i=0; i<n; i++){
            
            int num = nums[i];
            int cnt=1;
            
            while(find(nums, num+1) == true){
                num = num + 1;
                cnt++;
            }
            
            longest = max(longest, cnt);
        }
        return longest;
    }
    
    int better(vector<int>& nums){
        
        int n = nums.size();
        if(n == 0)
            return 0;
        sort(begin(nums), end(nums));
        
        int cnt=0;
        int longest = 1;
        int lastSmaller = INT_MIN;
        
        for(int i=0; i<n; i++){
            
            if(nums[i] - 1 == lastSmaller){
                cnt = cnt + 1;
                lastSmaller = nums[i];
            }
            else if(nums[i] != lastSmaller){
                cnt = 1;
                lastSmaller = nums[i];
            }
            
            longest = max(longest, cnt);
        }
        
        return longest;
    }
    
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0)
            return 0;
        
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 1;
        
        for(auto it : st){
            
            if(st.find(it-1) == st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x+1;
                    cnt = cnt+1;
                }
                
                longest = max(longest, cnt);
            }
        }
        
        return longest;
    }
};