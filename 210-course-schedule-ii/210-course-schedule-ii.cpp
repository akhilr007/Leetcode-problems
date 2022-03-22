class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> graph[numCourses];
        
        for(vector<int> vec : prerequisites){
            int u = vec[1];
            int v = vec[0];
            
            graph[u].push_back(v);
        }
        
        vector<int> indegree(numCourses, 0);
        
        for(int v=0; v<numCourses; v++){
            for(int x : graph[v]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count=0;
        vector<int> res;
        while(q.size() > 0){
            
            int rem = q.front();
            q.pop();
            count++;
            
            res.push_back(rem);
            
            for(int x : graph[rem]){
                if(--indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        
        if(count != numCourses) return {};
        
        return res;
    }
};