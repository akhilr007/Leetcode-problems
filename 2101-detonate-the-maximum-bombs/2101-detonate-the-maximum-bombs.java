class Solution {
    public void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited, int[] count){
        
        visited[node] = true;
        count[0]++;
        
        for(int adjNode: adj.get(node)){
            
            if(visited[adjNode] == false){
                
                dfs(adjNode, adj, visited, count);
            }
        }
    }
    
    public int maximumDetonation(int[][] bombs) {
        
        int n = bombs.length;
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(n);
        
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                
                if(i == j)
                    continue;
                
                long x1 = bombs[i][0];
                long y1 = bombs[i][1];
                long r1 = bombs[i][2];
                
                long x2 = bombs[j][0];
                long y2 = bombs[j][1];
                long r2 = bombs[j][2];
                
                long distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if((long)r1*r1 >= distance){
                    adj.get(i).add(j);
                }
                
            }
        }
        
        boolean[] visited = new boolean[n];
        Arrays.fill(visited, false);
        
        int result = 0;
        for(int i=0; i<n; i++){
            
            int[] count = new int[1];
            
            dfs(i, adj, visited, count);
            
            result = Math.max(result, count[0]);
            Arrays.fill(visited, false);
        }
        
        return result;
        
    }
}