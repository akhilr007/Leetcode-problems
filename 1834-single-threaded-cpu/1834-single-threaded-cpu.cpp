class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        
        vector<pair<long, pair<long, long>>> task;
        for(int i=0; i<tasks.size(); i++){
            task.push_back({tasks[i][0], {tasks[i][1], i} });
        }
        
        sort(begin(task), end(task)); // sort wrt enque time
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // [processingTime, index]
        long i = 0, cur_time = task[0].first; // i -> cur_task 
        
        vector<int> res;
        while(!pq.empty() or i < n){
            
            // if the cur_task is less than total task
            // if the cur_time is greater than or equal to some enque_time
            while(i < n and cur_time >= task[i].first){
                long processingTime = (long)task[i].second.first;
                long index = (long)task[i].second.second;
                pq.push({processingTime, index});
                i++;
            }
            
            // if cpu is idle or pq is empty then make cur_time to the next_available_time
            if(pq.empty() == true){
                cur_time = task[i].first;
            }
            else{
                auto it = pq.top();
                pq.pop();
                long processingTime = it.first;
                long index = it.second;
                
                res.push_back(index);
                cur_time += (long)processingTime;
            }
        }
        
        return res;
    }
};