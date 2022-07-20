class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int>> alpha(26);
        
        for(int i=0; i<s.size(); i++){
            alpha[s[i] - 'a'].push_back(i);
        }
        
        int num_found = 0;
        
        for(auto word: words){
            
            int cur_idx = -1;
            bool found = true;
            
            for(char c : word){
                
                auto it = upper_bound(alpha[c-'a'].begin(), alpha[c-'a'].end(), cur_idx);
                if(it == alpha[c-'a'].end()) found = false;
                else cur_idx = *it;
            }
            
            if(found) num_found++;
        }
        
        return num_found;
    }
};