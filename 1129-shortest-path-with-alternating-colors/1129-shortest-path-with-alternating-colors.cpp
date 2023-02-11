class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> red[n];
        vector<int> blue[n];
        
        for(auto& it: redEdges)
            red[it[0]].push_back(it[1]);
        
        for(auto& it: blueEdges)
            blue[it[0]].push_back(it[1]);
        
        
        queue<pair<int, pair<int, string>>> q;
        q.push({0, {0, "NULL"}});
        
        set<pair<int, string>> vis;
        vis.insert({0, "NULL"});
        
        vector<int> answer(n, -1);
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            
            int node = it.first;
            int length = it.second.first;
            string edgeColor = it.second.second;
            
            if(answer[node] == -1)
                answer[node] = length;
            
            if (edgeColor != "RED"){
                for(auto& node : red[node]){
                    if(vis.find({node, "RED"}) == vis.end()){
                        vis.insert({node, "RED"});
                        q.push({node, {length+1, "RED"}});
                    }
                }
            }
            
            
            if(edgeColor != "BLUE"){
                for(auto& node: blue[node]){
                    if(vis.find({node, "BLUE"}) == vis.end()){
                        vis.insert({node, "BLUE"});
                        q.push({node, {length+1, "BLUE"}});
                    }
                }
            }
        }
        
        return answer;
    }
};