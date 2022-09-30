class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> heights;
        
        // taking starting point as -ve and ending point as +ve
        for(auto building : buildings){
            heights.push_back({building[0], -building[2]});
            heights.push_back({building[1], building[2]});
        }
        
        sort(heights.begin(), heights.end());
        
        multiset<int> mset = {0};
        int prevMaxHeight = 0;
        int curMaxHeight;
        
        vector<vector<int>> result;
        
        for(auto h : heights){
            if(h.second < 0){
                // it is a starting point of a building we can insert it
                mset.insert(-h.second);
            }
            else{
                mset.erase(mset.find(h.second));
            }
            
            curMaxHeight = *mset.rbegin();
            if(curMaxHeight != prevMaxHeight){
                vector<int> ans(2);
                ans[0] = h.first;
                ans[1] = curMaxHeight;
                prevMaxHeight = curMaxHeight;
                result.push_back(ans);
            }
        }
        
        return result;
    }
};