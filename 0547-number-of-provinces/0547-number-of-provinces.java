class Solution {
    public  void dfs(int node, List<List<Integer>> adj, boolean[] visited){
        
        visited[node] = true;
        
        for(int adjNode : adj.get(node)){
            if(visited[adjNode] == false){
                dfs(adjNode, adj, visited);
            }
        }
    }
    
    public int findCircleNum(int[][] isConnected) {
        
        int n = isConnected.length;
        
        List<List<Integer>> adj = new ArrayList<>(n);
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                
                if(i == j)
                    continue;
                
                if(isConnected[i][j] == 1){
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        
        int result = 0;
        
        for(int i=0; i<n; i++){
            if(visited[i] == false){
                dfs(i, adj, visited);
                result++;
            }
            
        }
        
        return result;
    }
}