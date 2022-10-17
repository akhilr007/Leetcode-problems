class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> m;
        for(auto& ch : sentence){
            m[ch]++;
        }
        
        return m.size() == 26 ? true : false;
    }
};