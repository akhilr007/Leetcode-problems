class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        unordered_set<int> s(arr.begin(), arr.end());
        
        int itr=1;
        while(k > 0){
            
            if(s.find(itr) == s.end())
                k--;
            itr++;
        }
        
        return itr-1;
    }
};