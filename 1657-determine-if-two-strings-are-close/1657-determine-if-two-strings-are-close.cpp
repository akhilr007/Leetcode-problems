class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        int m = word1.length();
        int n = word2.length();
        
        if(m != n) return false;
        
        vector<int> freq1(26, 0), freq2(26, 0);
        
        for(int i=0; i<m; i++){
            int idx1 = word1[i]-'a';
            int idx2 = word2[i]-'a';
            
            freq1[idx1]++;
            freq2[idx2]++;
        }
        
        for(int i=0; i<26; i++){
            if(freq1[i] != 0 and freq2[i] != 0) continue;
            if(freq1[i] == 0 and freq2[i] == 0) continue;
            return false;
        }
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
        
    }
};