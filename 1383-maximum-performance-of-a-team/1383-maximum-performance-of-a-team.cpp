class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int, int>> engineers(n);
        for(int i=0; i<n; i++){
            engineers[i].first = efficiency[i];
            engineers[i].second = speed[i];
        }
        
        sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq; // to get speed
        long res=0, sumS = 0;
        int MOD = 1e9+7;
        for(auto& [e, s] : engineers){
            
            pq.push(s);
            sumS += s;
            cout<<"sumS -> "<<sumS<<" ";
            
            if(pq.size()>k){
                cout<<"pq -> " << pq.top()<< " ";
                sumS -= pq.top();
                cout<<sumS<<" ";
                pq.pop();
            }
            
            res = max(res, e * sumS);
            cout<<"res -> "<<res<<endl;
        }
        
        return (res % MOD);
    }
};