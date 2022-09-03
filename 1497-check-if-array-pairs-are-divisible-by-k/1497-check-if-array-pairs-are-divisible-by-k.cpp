class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        if(arr.size()%2) return false;
        // fmap of remainder of arr
        unordered_map<int, int> fmap;
        for(auto val : arr){
            int rem = ((val%k)+k)%k;
            fmap[rem]++;
        }
        
        for(auto val : arr){
            
            int rem = ((val%k)+k)%k;
            
            if(rem == 0){
                if(fmap[rem] % 2) return false;
            }
            else{
                if(fmap[rem] != fmap[k - rem]) return false;
            }
        }
        
        return true;
    }
};