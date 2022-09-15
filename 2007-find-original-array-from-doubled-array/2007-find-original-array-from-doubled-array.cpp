class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n=changed.size();
        if(n%2) return {};
        
        vector<int> count(100001, 0);
        vector<int> ans(n/2, 0);
        for(int val : changed){
            count[val]++;
        }
        
        int idx=0;
        for(int i=0; i<count.size(); i++){
            while(count[i]>0 && i*2<count.size() && count[i*2]>0){
                count[i]--;
                count[i*2]--;
                ans[idx++]=i;
            }
        }
        
        for(int i=0; i<count.size(); i++){
            if(count[i]>0) return {};
        }
        
        return ans;
    }
};