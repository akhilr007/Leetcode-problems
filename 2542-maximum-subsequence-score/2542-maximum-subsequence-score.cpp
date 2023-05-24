class Solution {
public:
    unordered_map<string, long long> mp;
    long long solve(int idx, long long sum, int min_ele, int count, vector<int>& nums1, vector<int>& nums2, int k){
        
        if(count == k){
            return sum * min_ele;
        }
        
        if(idx >= nums1.size()){
            return 0;
        }
        
        string key = to_string(idx) + "-" + to_string(sum) + "-" + to_string(min_ele) + to_string(count);
        
        if(mp.find(key) != mp.end()){
            return mp[key];
        }
        
        long long take = solve(idx+1, sum+nums1[idx], min(min_ele, nums2[idx]), count+1, nums1, nums2, k);
        
        long long notTake = solve(idx+1, sum, min_ele, count, nums1, nums2, k);
        
        return mp[key] = max(take, notTake);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        
        vector<pair<int, int>> pairs;
        for(int i=0; i<n; i++){
            pairs.push_back({ nums1[i], nums2[i] });
        }
        
        sort(begin(pairs), end(pairs), [&](const pair<int, int>&a, const pair<int, int>& b){
            return a.second > b.second;
        });
        
        priority_queue<int, vector<int>, greater<int>> topKHeap;
        long long res = 0, topKSum = 0;
        
        for(int i=0; i<k; i++){
            topKSum += pairs[i].first;
            topKHeap.push(pairs[i].first);
        }
        
        res = topKSum * pairs[k-1].second;
        
        for(int i=k; i<n; i++){
            
            topKSum += pairs[i].first - topKHeap.top();
            topKHeap.pop();
            
            topKHeap.push(pairs[i].first);
            res = max(res, topKSum * pairs[i].second);
        }
        
        return res;
    }
};