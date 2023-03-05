class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        int steps = 0;
        while(!q.empty()){
            
            int size = q.size();
            while(size-- > 0){
                
                int cur = q.front();
                q.pop();
                
                if(cur == n-1)
                    return steps;
                
                int left = cur - 1;
                int right = cur + 1;
                
                if(left >= 0 && !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
                
                if(right < n && !visited[right]){
                    q.push(right);
                    visited[right] = true;
                }
                
                for(int &idx : mp[arr[cur]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                
                mp.erase(arr[cur]);
            }
            
            steps++;
        }
        
        return -1;
    }
};