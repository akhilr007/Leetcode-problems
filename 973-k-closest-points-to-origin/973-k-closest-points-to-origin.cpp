class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>> pq;
        for(int i=0; i<points.size(); i++){
            
            long dist = (points[i][0])*(points[i][0]) + (points[i][1])*(points[i][1]);
            
            if(pq.size() < k){
                pq.push({dist, points[i]});
            }
            else{
                pq.push({dist, points[i]});
                pq.pop();
            }
        }
        
        vector<vector<int>> res;
        while(pq.size()>0){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};