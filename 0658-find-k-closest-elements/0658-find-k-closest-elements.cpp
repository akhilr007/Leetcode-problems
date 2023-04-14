class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            pq.push({ abs(arr[i] - x), i});
        }
        
        vector<int> res;
        while(k--){
            res.push_back(arr[pq.top().second]);
            pq.pop();
        }
        
        sort(begin(res), end(res));
        return res;
    }
};