class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<m; i++){
            int sum=0;
            int j;
            for(j=0; j<n; j++){
                sum += nums[j];
                if(sum > queries[i]){
                    ans[i] = j;
                    break;
                }
            }
            
            if(sum <= queries[i]){
                ans[i] = j;
            }
        }
        
        return ans;
    }
};