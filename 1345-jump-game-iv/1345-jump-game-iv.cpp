class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        unordered_map<int, vector<int>> m;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]].push_back(i);
        }
        
        int n=arr.size();
        vector<bool> visit(n, false);
        queue<int> q;
        q.push(0);
        
        int level=0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                
                int head = q.front(); q.pop();
                
                if(head == n-1) return level;
                
                if(head < 0 || head > n || visit[head]) continue;
                
                if(head-1 > 0 && !visit[head]){
                    q.push(head-1);
                }
                
                if(head+1 < n && !visit[head]){
                    q.push(head+1);
                }
                
                if(m.find(arr[head]) != m.end()){
                    for(int idx : m[arr[head]]){
                        if(idx > 0 && idx < n && !visit[idx]){
                            q.push(idx);
                        }
                    }
                    m.erase(arr[head]);
                }
                visit[head] = true;
            }
            level++;
        }
        
        return -1;
    }
};