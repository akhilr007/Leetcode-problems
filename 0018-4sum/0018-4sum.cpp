class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        set<vector<int>> st;
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                
                set<long long> s;
                for(int k=j+1; k<n; k++){
                    
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                     
                    long long fourth = target - sum;
                    
                    if(s.find(fourth) != s.end()){
                        
                        vector<int> t = {nums[i], nums[j], nums[k], (int)fourth };
                        sort(begin(t), end(t));
                        
                        st.insert(t);
                    }
                    
                    s.insert(nums[k]);
                }
            }
        }
        
        vector<vector<int>> res(begin(st), end(st));
        return res;
    }
};