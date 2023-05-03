class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> m1, m2;
        for(auto n: nums1)
            m1[n] ++;
        
        for(auto n: nums2)
            m2[n] ++;
        
        vector<vector<int>> ans(2);
        
        vector<int> res1;
        for(auto n: nums1){
            
            if(m2.find(n) == m2.end()){
                res1.push_back(n);
                m2[n] ++;
            }
        }
        
        vector<int> res2;
        for(auto n: nums2){
            
            if(m1.find(n) == m1.end()){
                res2.push_back(n);
                m1[n] ++;
            }
        }
        
        ans[0] = res1;
        ans[1] = res2;
        return ans;
    }
};