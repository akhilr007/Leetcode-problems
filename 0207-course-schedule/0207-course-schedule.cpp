class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // build adjacency list
        vector<int> adj[numCourses];
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // create indegree array
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto node: adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto nbr: adj[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0) q.push(nbr);
            }
        }
        
        return cnt == numCourses;
    }
};