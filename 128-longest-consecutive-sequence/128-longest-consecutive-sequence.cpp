class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s;
        for(auto el : nums){
            s.insert(el);
        }
        
        int longest=0;
        
        for(auto n: nums){
            // check if its the start of a sequence
            if(s.find(n-1) == s.end()){
                int length = 0;
                while(s.find(n + length) != s.end()){
                    length += 1;
                    longest = max(length, longest);
                }
            }
        }
        
        return longest;
    }
};