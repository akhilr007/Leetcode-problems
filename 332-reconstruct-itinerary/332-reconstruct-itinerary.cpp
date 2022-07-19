class Solution {
public:
    void dfs(string src, unordered_map<string, queue<string>>& adj,
             vector<vector<string>>& tickets, vector<string>& res){
        
        auto& q = adj[src];
        while(q.size()>0){
            
            string nbr = q.front();
            q.pop();
            
            dfs(nbr, adj, tickets, res);
            
        }
        
        res.push_back(src);
        
    }
             
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        sort(tickets.begin(), tickets.end());
        
        unordered_map<string, queue<string>> adj;
        
        for(auto ticket: tickets){
            adj[ticket[0]].push(ticket[1]);
        }
        
        
        vector<string> res;
        dfs("JFK", adj, tickets, res);
        reverse(res.begin(), res.end());
        
        return res;
    }
};