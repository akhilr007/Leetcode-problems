class Solution {
public:
    
    void dfs(string src, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& m, vector<string>& ans){
        
        auto& nbrs = m[src];
        
        while(nbrs.size()>0){
            string nbr = nbrs.top();
            nbrs.pop();
            
            dfs(nbr, m, ans);
        }
        
        ans.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        // min priority queue
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;
        
        for(auto ticket : tickets){
            
            if(m.find(ticket[0]) != m.end()){
                priority_queue<string, vector<string>, greater<string>> p;
                p = m[ticket[0]];
                p.push(ticket[1]);
                m[ticket[0]] = p;
            }
            else{
                m[ticket[0]].push(ticket[1]);
            }
        }
    
        
        vector<string> ans;
        dfs("JFK", m, ans);
        
        reverse(ans.begin(), ans.end());
        
        
        return ans;
        
    }
};