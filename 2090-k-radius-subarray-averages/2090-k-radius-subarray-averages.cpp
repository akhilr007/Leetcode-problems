class Solution {
public:
    vector<int> brute(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> result(n, -1);
        
        for(int i=k; i<n-k; i++){
            
            int sum=0;
            for(int j=i-k; j<=i+k; j++){
                sum += nums[j];
                result[i] = (sum / (2*k+1));
            }
        }
        
        return result;
    }
    
    vector<int> better(vector<int>& nums, int k){
        
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
    
    vector<int> getAverages(vector<int>& nums, int k) {
        
        if(k == 0)
            return nums;
        
        int n = nums.size();
        vector<int> result(n, -1);
        
        if(2*k+1 > n)
            return result;
        
        long long windowSum = 0;
        
        for(int i=0; i<2*k+1; i++){
            windowSum += nums[i];
        }
        
        result[k] = windowSum / (2*k+1);
        
        for(int i=2*k+1; i<n; i++){
            
            windowSum = windowSum - nums[i-(2*k+1)] + nums[i];
            result[i-k] = windowSum / (2*k+1); 
        }
        
        return result;
        
        
    }
};