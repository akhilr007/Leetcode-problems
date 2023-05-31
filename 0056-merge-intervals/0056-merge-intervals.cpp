class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        
        
        vector<vector<int>> result;
        vector<int> temp = intervals[0]; // [1, 3]
        
        for(auto interval: intervals){
            
            if(interval[0] <= temp[1]){
                temp[0] = min(temp[0], interval[0]);
                temp[1] = max(temp[1], interval[1]);
            }
            else{
                result.push_back(temp);
                temp = interval;
            }
        }

        result.push_back(temp);
        return result;
    }
};