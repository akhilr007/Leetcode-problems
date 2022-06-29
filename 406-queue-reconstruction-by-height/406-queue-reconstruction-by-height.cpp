class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        vector<vector<int>> result;
        
        sort(people.begin(), people.end(), comp);
        
        for(auto p : people){
            result.insert(result.begin()+p[1], p);
        }
        
        return result;
    }
};