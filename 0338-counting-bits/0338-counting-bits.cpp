class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> result;
        
        for(int index=0; index<=n; index++){
            int number = index;
            
            result.push_back(__builtin_popcount(number));
        }
        return result;
    }
};