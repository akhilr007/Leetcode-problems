class Solution {
public:
    vector<int> brute(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> result(n);
        
        for(int i=0; i<n; i++){
            
            if(i-k>=0 && i+k<n){
                int sum = 0;
                int cnt=0;
                for(int j=i-k; j<=i+k; j++){
                    sum += nums[j];
                    cnt++;
                }
                
                result[i] = (sum / cnt);
            }
            else{
                result[i] = -1;
            }
        }
        
        return result;
    }
    
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k == 0)
            return nums;
        
        int n = nums.size();
        vector<int> averages(n, -1);
        
        if(k > 2*k+1)
            return averages;
        
        vector<long long> prefixSum(n+1);
        
        for(int i=0; i<n; i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
        
        for(int i=k; i<(n-k); i++){
            
            int leftBound = i-k; 
            int rightBound = i+k;
            
            long long subarraySum = prefixSum[rightBound+1] - prefixSum[leftBound];
            int average = subarraySum / (2*k+1);
            
            averages[i] = average;
        }
        
        return averages;
    }
};