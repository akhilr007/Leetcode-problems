class Solution {
private:
    int bruteForce(vector<int>& arr){
        vector<int> minimums;
        int n = arr.size();

        for(int i=0; i<arr.size(); i++){
            int mini = arr[i];
            for(int j=i; j<arr.size(); j++){
                if(arr[i] == arr[j]){
                    minimums.push_back(mini);
                    continue;
                }

                mini = min(mini, arr[j]);
                minimums.push_back(mini);
            }
        }

        int MOD = 1e9+7;
        long sum = 0;
        for(auto val: minimums){
            sum = (sum % MOD + val % MOD) % MOD;
        }

        return sum;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        int nsl[n];
        
        stack<int> st;
        for(int i=0; i<n; i++){
            
            while(st.size()>0 && arr[st.top()] >= arr[i]) st.pop();
            
            if(st.size() == 0){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top();
            }
            
            st.push(i);
        }
        
        while(st.size()>0) st.pop();
        int nsr[n];
        
        for(int i=n-1; i>=0; i--){
            while(st.size()>0 && arr[st.top()] > arr[i]) st.pop();
            
            if(st.size() == 0){
                nsr[i] = n;
            }
            else{
                nsr[i] = st.top();
            }
            
            st.push(i);
        }
        
        int MOD = 1e9+7;
        long sum = 0;
        
        for(int i=0; i<n; i++){
            
            long product = arr[i]*(long)(i-nsl[i])*(nsr[i]-i);
            sum = (sum % MOD + product % MOD) % MOD;
        }
        
        return sum;
    }
};