class Solution {
    
    boolean isDFSCycle(int u, List<List<Integer>> adj, boolean[] visited, boolean[] inRecursion){
        
        visited[u]=true;
        inRecursion[u]=true;
        
        for(int v : adj.get(u)){
            if(visited[v]==false && isDFSCycle(v, adj, visited, inRecursion)){
                return true;
            }
            else if(inRecursion[v] == true){
                return true;
            }
        }
        
        inRecursion[u]=false;
        return false;
    }
    
    boolean dfs(int numCourses, int[][] prerequisites) {
        
        boolean[] visited = new boolean[numCourses];
        boolean[] inRecursion = new boolean[numCourses];
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0;i<numCourses;i++){
            adj.add(new ArrayList<>());
        }
        
        for(int i=0; i<prerequisites.length; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj.get(v).add(u);
        }
        
        for(int i=0; i<numCourses; i++){
            if(visited[i] == false && isDFSCycle(i, adj, visited, inRecursion)==true){
                return false;
            }
        }
        
        return true;
    }
    
    boolean topoSort(List<List<Integer>> adj, int[] indegree, int numCourses){
        
        Queue<Integer> q = new LinkedList<>();
        
        int count=0;
        for(int i=0; i<indegree.length; i++){
            if(indegree[i]==0){
                q.offer(i);
                count++;
            }
        }
        
        
        while(q.size()>0){
            
            int u = q.poll();
            
            for(int v: adj.get(u)){
                
                indegree[v]--;
                
                if(indegree[v] == 0){
                    q.offer(v);
                    count++;
                }
            }
        }
        
        return count == numCourses ? true : false;
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<numCourses; i++){
            adj.add(new ArrayList<>());
        }
        
        // create graph
        int[] indegree = new int[numCourses];
        for(int i=0; i<prerequisites.length; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            adj.get(v).add(u); 
            indegree[u]++;
        }
        
        return topoSort(adj, indegree, numCourses);
    }
}