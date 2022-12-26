class Solution {
public:
    bool solveRec(int idx, vector<int>& nums, int n, vector<int>& t){
        
        if(idx == n-1) return true;
        if(t[idx] != -1) return t[idx];
        
        for(int jump=1; jump<=nums[idx]; jump++){
            if(solveRec(idx+jump, nums, n, t)) return t[idx] = true;
        }
        
        return t[idx] = false;
    }
    
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> t(n+1, -1);
        return solveRec(0, nums, n, t);
    }
};