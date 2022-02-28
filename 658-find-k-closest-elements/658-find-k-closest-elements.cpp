class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int lo = 0;
        int hi = arr.size()-1;
        
        while(hi-lo >= k){
            
            if(abs(arr[lo]-x) > abs(arr[hi]-x)) lo++;
            else hi--;
        }
        
        vector<int> res;
        for(int i=lo; i<=hi; i++){
            res.push_back(arr[i]);
        }
        
        return res;
        
    }
};