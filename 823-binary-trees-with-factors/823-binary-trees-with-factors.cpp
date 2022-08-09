class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        if(arr.size() == 0) return 0;
        
        unordered_map<int, long> m;
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            long count = 1;
            for(int j=0; j<i; j++){
                if((arr[i]%arr[j]==0) && m.find(arr[i]/arr[j]) != m.end()){
                    count += m[arr[j]] * m[arr[i]/arr[j]];
                }
            }
            
            m[arr[i]] = count;
        }
        
        long totalCount=0;
        long mod = (long)1e9+7;
        for(auto key : m){
            totalCount += key.second;
        }
        
        totalCount = (totalCount % mod);
        return (int)totalCount;
    }
};