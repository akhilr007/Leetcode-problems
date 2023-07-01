class Solution {
public:
    void solve(int idx, vector<int>& children, int& result, vector<int>& cookies, int k){
        
        if(idx >= cookies.size()){
            
            int unfairness = *max_element(begin(children), end(children));
            result = min(result, unfairness);
            return;
        }
        
        int cookie = cookies[idx];
        for(int i=0; i<k; i++){
            
            children[i] += cookie;
            solve(idx+1, children, result, cookies, k);
            children[i] -= cookie;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n = cookies.size();
        vector<int> children(k, 0);
        
        int result = INT_MAX;
        solve(0, children, result, cookies, k);
        return result;
    }
};