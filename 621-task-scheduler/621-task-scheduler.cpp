class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<int, int> m; // "a" -> no_of_counts
        for(auto x : tasks){
            m[x]++;
        }
        
        priority_queue<int> pq; // max heap
        for(auto x : m){
            pq.push(x.second);
        }
        queue<pair<int, int>> q; // pair -> {cnt, idle_time}
        
        
        int time = 0;
        while(!pq.empty() or !q.empty()){
            
            time++;
            if(!pq.empty()){
                int cnt = pq.top() - 1;// -1 bcoz we have processed one task
                pq.pop();
                if(cnt > 0){
                    q.push({cnt, time + n});
                }
            }
            
            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};