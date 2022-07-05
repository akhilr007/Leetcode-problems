class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numSet;
        for(auto el : nums) numSet.insert(el);
        
        int longest=0;
        for(auto n: nums){
            if(numSet.find(n-1) == numSet.end()){
                int length = 0;
                while(numSet.find(n+length) != numSet.end()){
                    length += 1;
                    longest = max(longest, length);
                }
            }
        }
        
        return longest;
    }
};