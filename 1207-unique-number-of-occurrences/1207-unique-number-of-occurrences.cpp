class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_set<int> count;
        unordered_map<int, int> countMap;
        
        for(int val: arr) countMap[val]++;
        for(auto& it: countMap){
            if(count.find(it.second) != count.end()) return false;
            count.insert(it.second);
        }
        
        return true;
    }
};