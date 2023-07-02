class Solution {
public:
    int ans=0;
    void solve(int i, vector<vector<int>>& requests, int numberOfRequestsProcessed, vector<int>& requestProcessed){
        
        if(i == requests.size()){
            
            for(auto r: requestProcessed){
                if(r != 0)
                    return;
            }
            
            ans = max(ans, numberOfRequestsProcessed);
            return;
        }
        
        // not processing the request
        solve(i+1, requests, numberOfRequestsProcessed, requestProcessed);
        
        // process this request
        requestProcessed[requests[i][0]]--;
        requestProcessed[requests[i][1]]++;
        
        solve(i+1, requests, 1+numberOfRequestsProcessed, requestProcessed);
        
        requestProcessed[requests[i][0]]++;
        requestProcessed[requests[i][1]]--;
    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> requestProcessed(n, 0);
        solve(0, requests, 0, requestProcessed);
        
        return ans;
    }
};