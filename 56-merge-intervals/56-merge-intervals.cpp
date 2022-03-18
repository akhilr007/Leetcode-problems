class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return intervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        vector<int> temp = intervals[0];
        
        for(auto it : intervals){
            
            if(it[0] <= temp[1]){
                
                temp[1] = max(it[1], temp[1]);
                
            }
            else{
                res.push_back(temp);
                temp = it;
            }
        }
        
        res.push_back(temp);
        return res;
    }
};