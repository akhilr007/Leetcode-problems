class Solution {
public:
    void dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& m, unordered_set<string>& s, double& ans, double temp){
        
        // if visited return
        if(s.find(src) != s.end()) return;
        
        s.insert(src);
        if(src == dest){
            ans = temp;
            return;
        }
        
        for(auto i : m[src]){
            
            dfs(i.first, dest, m, s, ans, temp * i.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> m;
        
        for(int i=0; i<equations.size(); i++){
            m[equations[i][0]].push_back({equations[i][1], values[i]});
            m[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        vector<double> res;
        
        for(int i=0; i<queries.size(); i++){
            string src = queries[i][0];
            string dest = queries[i][1];
            
            unordered_set<string> s;
            
            double ans = -1.0;
            
            // agar src map me nai h to ans -1 hai
            if(m.find(src) != m.end()){
                dfs(src, dest, m, s, ans, 1.0);
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};