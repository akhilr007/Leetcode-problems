class Solution {
public:
    int solve(int idx, int diff, vector<int>& arr){
        
        int result = 0;
        for(int j=idx+1; j<arr.size(); j++){
            
            int prevVal = arr[idx];
            int currVal = arr[j];
            
            if(currVal - prevVal == diff){
                result = max(result, 1 + solve(j, diff, arr));
            }
        }
        
        return result;
    }
    
    int brute(vector<int>& arr, int difference){
        
        int result = 0;
        
        for(int i=0; i<arr.size(); i++){
            result = max(result , 1 + solve(i, difference, arr));
        }
        
        return result;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> mp;
        
        int result = 1;
        
        for(int i=0; i<arr.size(); i++){
            
            if(mp.find(arr[i]-difference) != mp.end()){
                mp[arr[i]] = mp[arr[i]-difference]+1;
                result = max(result, mp[arr[i]]);
            }
            else{
                mp[arr[i]] = 1;
            }
        }
        return result;
    }
};