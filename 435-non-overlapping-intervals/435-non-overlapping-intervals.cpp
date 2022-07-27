class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int res = 0;
        
        int prevEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            
            int start = intervals[i][0],end = intervals[i][1];
            
            if(start >= prevEnd){
                prevEnd = end;
            }
            else{
                res++;
                prevEnd = min(prevEnd, end);
            }
        }
        
        return res;
    }
};