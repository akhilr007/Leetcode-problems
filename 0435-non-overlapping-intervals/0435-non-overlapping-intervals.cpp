class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(begin(intervals), end(intervals));
        
        int prevEnd = intervals[0][1];// last ending time
        int res = 0;
        
        for(int i=1; i<intervals.size(); i++){
            
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            
            if(curStart >= prevEnd){
                // it means non overlap, so change the prevEnd to curEnd
                prevEnd = curEnd;
            }
            else{
                // overlap to hai, to nikalna to hai so ++
                res++;
                // par nikalna kisko hai
                // [1, 2] [1, 3]->[1-2,2-3]
                // agar 1,3 ko nahi nikaloge it means apko 2 elements ignore karne
                // par sakte hai, which acc to question is bad
                // so ap usko nikaloge jo bada interval hai, fir mujhe kam intervals
                // ko nikalne padenge
                prevEnd = min(curEnd, prevEnd);
            }
            
            
        }
        
        return res;
    }
};