class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        
        vector<pair<int, int>> pairs;
        for(int i=0; i<n; i++){
            pairs.push_back({ nums1[i], nums2[i] });
        }
        
        sort(begin(pairs), end(pairs), [&](const pair<int, int>&a, const pair<int, int>& b){
            return a.second > b.second;
        });
        
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long topKSum = 0;
        long long res = 0;
        
        for(int i=0; i<k; i++){
            
            topKSum += pairs[i].first;
            pq.push(pairs[i].first);
        }
        
        res = topKSum * pairs[k-1].second;
        
        for(int i=k; i<n; i++){
            
            topKSum += pairs[i].first - pq.top();
            pq.pop();
            
            pq.push(pairs[i].first);
            res = max(res, topKSum * pairs[i].second);
            
        }
        
        return res;
    }
};