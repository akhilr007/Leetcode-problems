class Solution {
public:
    int findLPS(string s, string r){
        
        int n = s.size();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                int ans=0;
                if(s[i-1] == r[j-1])
                    ans = 1 + prev[j-1];
                else
                    ans = max(prev[j], cur[j-1]);
                
                cur[j] = ans;
            }
            prev = cur;
        }
        
        return prev[n];
    }
    
    int minInsertions(string s) {
        
        int n = s.size();
        string r = s;
        reverse(begin(s), end(s));
        
        return n - findLPS(s, r);
    }
};