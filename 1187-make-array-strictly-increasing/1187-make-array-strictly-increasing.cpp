class Solution {
public:
    map<pair<int, int>, int> mp;
    
    int solve(int index, vector<int>& arr1, vector<int>& arr2, int prevValue){
        
        if(index >= arr1.size())
            return 0;
        if(mp.find({index, prevValue}) != mp.end())
            return mp[{index, prevValue}];
        
        int option1 = 1e9;
        if(arr1[index] > prevValue){
            option1 = solve(index+1, arr1, arr2, arr1[index]);
        }
         
        int option2 = 1e9;
        auto it = upper_bound(begin(arr2), end(arr2), prevValue);
        if(it != end(arr2)){
            
            int j = it - begin(arr2);
            option2 = 1 + solve(index+1, arr1, arr2, arr2[j]);
        }
        
        return mp[{index, prevValue}] = min(option1, option2);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
        sort(begin(arr2), end(arr2));
        int ans = solve(0, arr1, arr2, INT_MIN);
        
        return ans == 1e9 ? -1 : ans;
    }
};