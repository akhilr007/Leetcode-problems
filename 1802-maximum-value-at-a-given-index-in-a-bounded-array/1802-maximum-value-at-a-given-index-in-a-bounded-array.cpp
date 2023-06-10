class Solution {
public:
    long long getSumByFormula(long long count, long long val){
        
        return (long long)(count * val) - (long long)(count * (count+1))/2;
    }
    
    int better(int n, int index, int maxSum){
        
        int res = 0;
        
        for(int val=maxSum; val>=1; val--){
            
            // index -> no of elements in left side - left_count
            // val-1 -> val = 5, [4, 3, 2, 1] -> first n sum
            long long leftCount = min(index, val-1);
            long long leftSum = getSumByFormula(leftCount, val) + max(0, (index) - (val-1));
            
            long long rightCount = min(n-index-1, val-1);
            long long rightSum = getSumByFormula(rightCount, val) + max(0, (n-index-1) - (val-1));
            
            
            if((long long)(leftSum + val + rightSum) <= maxSum){
                res = val;
                break;
            }
        }
        
        return res;
    }
    
    int bruteForce(int n, int index, int maxSum){
        
        int res = 0;
        
        for(int val=maxSum; val>=1; val--){
            
            vector<int> arr(n, 0);
            
            arr[index] = val;
            
            int leftSum = 0;
            for(int i=index-1; i>=0; i--){
                
                arr[i] = arr[i+1] == 1 ? 1 : arr[i+1]-1;
                leftSum += arr[i];
            }
            
            int rightSum = 0;
            for(int i=index+1; i<n; i++){
                arr[i] = arr[i-1] == 1 ? 1 : arr[i-1] - 1;
                rightSum += arr[i];
            }
            
            if((leftSum + val + rightSum) <= maxSum){
                res = val;
                break;
            }
        }
        
        return res;
    }
    
    int maxValue(int n, int index, int maxSum) {
        
        int result = 0;
        
        int left = 1;
        int right = maxSum;
        
        while(left <= right){
            
            int mid = left + (right-left)/2;
            
            int val = mid;
            
            long long leftCount = min(index, val-1);
            long long leftSum = getSumByFormula(leftCount, val);
            leftSum += max(0, index-(val-1)); // for extra ones
            
            long long rightCount = min(n-index-1, val-1);
            long long rightSum = getSumByFormula(rightCount, val);
            rightSum += max(0, n-index-1-(val-1));
            
            long long totalSum = leftSum + val + rightSum;
            if(totalSum <= maxSum){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return result;
    }
};