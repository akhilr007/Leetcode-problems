class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int, int>> result;
        
        for(int index=0; index<arr.size(); index++){
            
            int number = arr[index];
            int count = 0;
            
            while(number > 0){
                if((number & 1) == 1)
                    count ++;
                
                number = number >> 1;
            }
            
            result.push_back({count, arr[index]});
        }
        
        sort(begin(result), end(result));
        
        vector<int> ans;
        
        for(auto p: result)
            ans.push_back(p.second);
        
        return ans;
    }
};