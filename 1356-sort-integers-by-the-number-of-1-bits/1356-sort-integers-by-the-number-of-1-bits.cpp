class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(begin(arr), end(arr), [](const auto &a, const auto &b){
            
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            
            return countA == countB ? a < b : countA < countB;
        });
        
        return arr;
    }
};