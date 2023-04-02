class Solution {
public:
    int find(vector<int>& potions, long long minPotion){
        
        int low = 0;
        int high = potions.size()-1;
    
        int ans = high+1;
        while(low <= high){
            
            int mid = (low + high) / 2;
            
            if(potions[mid] >= minPotion){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        int numberOfElementsGreaterThanMinPotion = potions.size()  - ans ;
        return numberOfElementsGreaterThanMinPotion;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        
        sort(begin(potions), end(potions)); // nlogn
        
        vector<int> res;
        for(int i=0; i<n; i++){ // nlogn
            
            // spell * minPotion >= success
            long long minPotion = ceil(success * 1.0 / spells[i]);
            if(minPotion > potions[m-1]){
                res.push_back(0);
                continue;
            }
            
            int numberOfSuccessfulPairs = find(potions, (int)minPotion);
            res.push_back(numberOfSuccessfulPairs);
        }
        
        return res;
    }
};