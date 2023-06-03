class Solution {
    public void dfs(int manager, List<List<Integer>> adj, int[] informTime, int curTime, int[] result){
        
        result[0] = Math.max(result[0], curTime);
        
        for(int employee : adj.get(manager)){
            
            dfs(employee, adj, informTime, curTime + informTime[manager] , result);
        }
    }
    
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        
        List<List<Integer>> adj = new ArrayList<>(n);
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<n; i++){
            
            int managerID = manager[i];
            int employeeID = i;
            
            if(managerID == -1)
                continue;
            
            adj.get(managerID).add(employeeID);
        }
        
        int[] result = new int[1];
        
        dfs(headID, adj, informTime, 0, result);
        
        return result[0];
    }
}