class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int, int> freq;
        for(auto& task: tasks){
            freq[task]++;
        }
        
        int res=0;
        for(auto [task, count]: freq){
            
            if(count == 1) return -1;
            
            if(count % 3 == 0){ // 3k
                res += count / 3;
            }
            else{
                // multiples of 3k + 1 or 3k + 2;
                res += (count / 3) + 1;
            }
        }
        
        return res;
    }
};