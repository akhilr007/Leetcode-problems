class Solution {
public:
    bool isSimilar(string& s1, string& s2){
        
        int count=0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i])
                count++;
        }
        
        return (count == 2 || count == 0);
    }
    
    void dfs(int i, vector<string>& strs, vector<bool>& vis){
        
        vis[i] = true;
        for(int j=0; j<strs.size(); j++){
            if(vis[j] == false){
                if(isSimilar(strs[i], strs[j]))
                    dfs(j, strs, vis);
            }
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        vector<bool> vis(n, false);
        
        int groups = 0;
        for(int i=0; i<n; i++){
            if(vis[i] == false){
                groups++;
                dfs(i, strs, vis);
            }
        }
        
        
        return groups;
    }
};