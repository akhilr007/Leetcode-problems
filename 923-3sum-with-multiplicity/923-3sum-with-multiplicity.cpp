class Solution {
private:
    int mod = (int)1e9+7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int, long> mp;
        for(auto el : arr){
            mp[el]++;
        }
        
        long ans=0;
        for(auto i: mp){
            for(auto j : mp){
                int el1 = i.first;
                int el2 = j.first;
                int el3 = target - el1 -el2;
                
                if(mp.find(el3) != mp.end()){
                    
                    long f1 = mp[el1];
                    long f2 = mp[el2];
                    long f3 = mp[el3];
                    
                    // case 1 if all the elements are same
                    if(el1 == el2 and el1 == el3){
                        // nc3
                        ans += ((f1)*(f1-1)*(f1-2))/6;
                    }
                    // case 2 first 2 elements are same and third is different
                    else if(el1 == el2 and el1 != el3){
                        // nc2 * nc1
                        ans += ((f1)*(f1-1))/2 * f3;
                    }
                    // case 3 all are different
                    else if(el1 < el2 and el2 < el3){
                        ans += f1*f2*f3;
                    }
                    ans = ans%mod;
                }
                
            }
        }
        
        return (int)ans;
    }
};