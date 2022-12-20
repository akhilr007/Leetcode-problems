class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis){
        
        vis[node] = 1;
        for(auto adjNode: rooms[node]){
            if(!vis[adjNode]){
                dfs(adjNode, rooms, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<int> vis(n, 0); // 0 -> false
        
        // room 0 is unlocked -> starting point is 0
        dfs(0, rooms, vis);
        
        for(auto v: vis){
            if(v == 0) return false;
        }
        
        return true;
    }
};