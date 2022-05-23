class Solution {
public:
    vector<int> findCount(string& s){
        
        vector<int> count(2);
        for(char ch : s){
            count[ch-'0']++;
        }
        
        return count;
    }
    
    int f(vector<string>& strs, int index, int zeros, int ones, vector<vector<vector<int>>>& dp){
        
        if(index == strs.size() || zeros + ones == 0){
            return 0;
        }
        
        if(dp[zeros][ones][index] != -1){
            return dp[zeros][ones][index];
        }
        
        vector<int> count = findCount(strs[index]);
    
        // consider the one and zero
        int consider = 0;
        if(zeros >= count[0] && ones >= count[1]){
            consider = 1 + f(strs, index+1, zeros-count[0], ones-count[1], dp);
        }
        
        // skip the one and zero
        int skip = f(strs, index+1, zeros, ones, dp);
        
        return dp[zeros][ones][index] = max(consider, skip);
    }
    
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        
        int n=strs.size();
        vector<vector<vector<int>>> dp(zeros+1, vector<vector<int>> (ones+1, vector<int>(n, -1)));
        return f(strs, 0, zeros, ones, dp);
    }
};