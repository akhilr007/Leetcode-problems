class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n+1), outdegree(n+1);
        
        for(auto &it: trust){
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }
        
        for(int i=1; i<=n; i++){
            if(outdegree[i] == 0 && indegree[i] == n-1)
                return i;
        }
        
        return -1;
    }
};