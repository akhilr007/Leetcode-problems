class Solution {
    int ans = 0;
    public void solve(int i, int[][] requests, int numberOfRequestProcessed, int[] requestProcessed){
        
        if(i >= requests.length){
            
            for(int r : requestProcessed)
                if(r != 0)
                    return;
            
            ans = Math.max(ans, numberOfRequestProcessed);
            return;
        }
        
        solve(i+1, requests, numberOfRequestProcessed, requestProcessed);
        
        requestProcessed[requests[i][0]]--;
        requestProcessed[requests[i][1]]++;
        
        solve(i+1, requests, 1+numberOfRequestProcessed, requestProcessed);
        
        requestProcessed[requests[i][0]]++;
        requestProcessed[requests[i][1]]--;
    }
    
    public int maximumRequests(int n, int[][] requests) {
        
        int[] requestProcessed = new int[n];
        
        solve(0, requests, 0, requestProcessed);
        
        return ans;
    }
}