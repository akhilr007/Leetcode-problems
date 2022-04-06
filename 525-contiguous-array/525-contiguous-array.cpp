class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        
        unordered_map<int, int> mp; // sum -> index
        mp[0] = -1;
        
        int len=0;
        int sum=0;
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i] == 0){
                sum += -1;
            }
            else if(arr[i] == 1){
                sum += 1;
            }
            
            if(mp.find(sum) != mp.end()){
                int curLen = i - mp[sum];
                len = max(curLen, len);
            }
            else{
                mp[sum] = i;
            }
        }
        
        return len;
    }
};