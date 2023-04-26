class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
        
        int n = arr.size();
        int totalSum = 0;
        for(auto it: arr)
            totalSum += it;
            
        /*
            s1 - s2 = d and, s1 + s2 = s -> s1 = s - s2
            s - s2 - s2 = d
            s - 2s2 = d
            s2 = (s - d)/2
        */
        
        if(totalSum - d < 0 || (totalSum - d) % 2)
            return 0;
            
        int target = (totalSum - d) / 2; 
        
        vector<int> prev(target+1, 0), cur(target+1, 0);
        
        // sum == 0 && arr[0] == 0 return 2 else 1
        if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
            
        // arr[0] == target
        if(arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;
            
        for(int index=1; index<n; index ++)
        {
            for(int t=0; t<=target; t++)
            {
                
                int not_taken = prev[t];
                int taken = 0;
                if(arr[index] <= t)
                    taken = prev[t-arr[index]];
                    
                cur[t] = (not_taken + taken);
            }
            
            prev = cur;
        }
        
        return prev[target];
    }
};