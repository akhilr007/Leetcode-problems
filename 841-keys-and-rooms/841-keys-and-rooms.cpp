class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector<bool>& vis){
        
        vis[src] = true;
        
        for(auto nbr : rooms[src]){
            if(vis[nbr] == false){
                dfs(nbr, rooms, vis);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> vis(n, false);
        
        dfs(0, rooms, vis);
        for(int i=0; i<n; i++){
            if(vis[i] == false) return false;
        }
        
        return true;
    }
};