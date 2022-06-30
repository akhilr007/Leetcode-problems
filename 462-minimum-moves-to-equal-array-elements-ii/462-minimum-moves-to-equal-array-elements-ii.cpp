class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int moves=0;
        sort(nums.begin(), nums.end());
        
        int i=0, j=nums.size()-1;
        while(i < j){
            
            moves += abs(nums[j] - nums[i]);
            i++;
            j--;
        }
        
        return moves;
    }
};