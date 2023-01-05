class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        sort(begin(points), end(points));
        
        vector<int> prev = points[0];
        
        vector<vector<int>> overlaps;
        for(int i=1; i<points.size(); i++){
            
            int prevStartingPoint = prev[0];
            int prevEndingPoint = prev[1];
            
            vector<int> cur = points[i];
            int curStartingPoint = cur[0];
            int curEndingPoint = cur[1];
            
            if(curStartingPoint > prevEndingPoint){
                // no overlap
                prev = cur;
                overlaps.push_back(prev);
            }
            else{
                prev[0] = max(prevStartingPoint, curStartingPoint);
                prev[1] = min(prevEndingPoint, curEndingPoint);
            }
        }
        
        overlaps.push_back(prev);
        //if(overlaps.size() == 0) return points.size();
        return overlaps.size();
    }
};