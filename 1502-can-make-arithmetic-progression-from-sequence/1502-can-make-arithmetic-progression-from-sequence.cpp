class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        unordered_set<int> s; // delta -> index;
        int delta = arr[1]-arr[0];
        s.insert(delta);
        
        for(int i=2; i<arr.size(); i++){
            
            delta = arr[i] - arr[i-1];
            
            if(s.find(delta) != s.end()){
                continue;
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};