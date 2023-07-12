class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        
        int n = graph.length;
        List<List<Integer>> adj = new ArrayList<>(n);
        
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        
        int[] indegree = new int[n];
        for(int i=0; i<n; i++){
            for(int v: graph[i]){
                adj.get(v).add(i);
                indegree[i]++;
            }
        }
        
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.offer(i);
            }
        }
        
        boolean[] safe = new boolean[n];
        while(q.size()>0){
            
            int u = q.poll();
            safe[u] = true;
            
            for(int v: adj.get(u)){
                indegree[v]--;
                if(indegree[v]==0){
                    q.offer(v);
                }
            }
            
        }
        
        List<Integer> result = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(safe[i] == true){
                result.add(i);
            }
        }
        
        return result;
    }
}