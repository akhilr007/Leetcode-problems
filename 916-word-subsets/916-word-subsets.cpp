class Solution {
public:
    vector<int> calculateFreqCount(string& s){
        
        vector<int> freq(26, 0);
        for(auto c : s){
            freq[c-'a']++;
        }
        
        return freq;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> res;
        vector<int> maxFreqCountAcrossB(26, 0);
        
        for(auto word : words2){
            vector<int> freqCount = calculateFreqCount(word);
            for(int i=0; i<26; i++){
                maxFreqCountAcrossB[i] = max(maxFreqCountAcrossB[i], freqCount[i]);
            }
        }
        
        for(auto word : words1){
            vector<int> freqCount = calculateFreqCount(word);
            bool foundChars = true;
            for(int i=0; i<26; i++){
                if(freqCount[i] < maxFreqCountAcrossB[i]){
                    foundChars = false;
                    break;
                }
            }
            
            if(foundChars) res.push_back(word);
        }
        
        
        return res;
    }
};