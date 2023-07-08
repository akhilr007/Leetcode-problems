class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        int n = weights.size();
        
        int m = n-1; // pair size
        vector<int> pairSum(m);
        for(int i=0; i<m; i++)
            pairSum[i] = weights[i] + weights[i+1];
        
        sort(begin(pairSum), end(pairSum));
        
        long long maxSum=0, minSum=0;
        for(int i=0; i<k-1; i++){
            minSum += pairSum[i];
            maxSum += pairSum[m-i-1];
        }
        
        return maxSum - minSum;
    }
};