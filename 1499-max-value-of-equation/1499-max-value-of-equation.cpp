class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, int>> pq;
        
        int ans=INT_MIN;
        
        for(int i=0; i<points.size(); i++){
            
            while(pq.size()>0 and (points[i][0] - pq.top().second > k)){
                pq.pop();
            }
            
            if(pq.size()>0){
                int xj=points[i][0];
                int yj=points[i][1];
                int yi_xi = pq.top().first;
                ans = max(ans, xj + yj + yi_xi);
            }
            
            int yi = points[i][1];
            int xi = points[i][0];
    
            pq.push({yi-xi, xi});
        }
        
        return ans;
    }
};