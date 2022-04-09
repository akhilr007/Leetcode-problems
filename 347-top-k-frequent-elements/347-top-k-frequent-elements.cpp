class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // count -> element
        unordered_map<int, int> mp;

        for(auto el: arr){
            mp[el]++;
        }


        for(auto it : mp){

            if(pq.size() < k){
                pq.push({it.second, it.first});
            }
            else{
                if(it.second > pq.top().first){
                    pq.pop();
                    pq.push({it.second, it.first });
                }
            }
        }

        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};