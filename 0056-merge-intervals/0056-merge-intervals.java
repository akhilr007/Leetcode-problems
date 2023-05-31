class Solution {
public:
    vector<vector<int>> brute(vector<vector<int>>& intervals){
        
        int n = intervals.size();
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
            
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            if(!ans.empty() && end <= ans.back()[1] )
                continue;
            
            for(int j=i+1; j<n; j++){
                
                if(intervals[j][0] <= end){
                    end = max(end, intervals[j][1]);
                }
                else{
                    break;
                }
            }
            
            ans.push_back({start, end});
        }
        
        return ans;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        return brute(intervals);
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