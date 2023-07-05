class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> indexes;
        for(int i=0; i<n; i++){
            if(nums[i]==0)
                indexes.push_back(i);
        }
        
        if(indexes.size()==0)
            return n-1;
        
        int result = 0;
        for(int k=0; k<indexes.size(); k++){
            
            int i=indexes[k]-1;
            int j=indexes[k]+1;
            
            while(i>=0){
                
                if(nums[i] == 0)
                    break;
                i--;
            }
            
            while(j<n){
                if(nums[j] == 0)
                    break;
                j++;
            }
            
            //cout<<j<<"->"<<i<<endl;
            result = max(result, j-i-2);
        }
        
        return result;
    }
};