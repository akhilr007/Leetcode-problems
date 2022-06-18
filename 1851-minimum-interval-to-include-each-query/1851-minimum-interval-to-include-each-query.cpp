/*
Brute force -> O(n*m) n -> length of intervals m-> length of queries

TC -> O(nlogn + qlogq)
Smarter way:
1. sort the intervals according to start time and sort query
2.

int idx=0
minHeap<interval_length, right_ending> candidate_list

for(query: queries){
    while(intervals[idx][0] <= query){
        insert_to_candidate_list
        idx++
    }
    
    while(right < query){
        pop candidate from candidate list
    }
    
    if(candidate_list_not_empty){
        insert into final list
    }
}
*/
class Solution {
public:
    vector<int> transformMap(unordered_map<int, int>& mp, vector<int>& queries){
        
        vector<int> result(queries.size());
        
        int idx=0;
        for(int query: queries){
            
            if(mp.find(query) != mp.end()){
                result[idx++] = mp[query];
            }
            else{
                result[idx++] = -1;
            }
        }
        
        return result;
    }
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        
        sort(intervals.begin(), intervals.end());
        vector<int> queryClone = queries;
        sort(queryClone.begin(), queryClone.end());
        
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> candidates;
        unordered_map<int, int> m;
        
        int idx=0;
        
        for(int query: queryClone){
            while(idx < intervals.size() && intervals[idx][0] <= query){
                
                int len = intervals[idx][1] - intervals[idx][0] + 1;
                int end = intervals[idx][1];
                
                candidates.push({len, end});
                idx++;
            }
            
            while(!candidates.empty() && candidates.top().second < query){
                candidates.pop();
            }
            
            if(!candidates.empty()){
                m[query] = candidates.top().first;
                
            }
            else{
                m[query] = -1;
            }
        }
        
        
        return transformMap(m, queries);
    }
};