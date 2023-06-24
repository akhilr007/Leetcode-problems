class Solution {
public:
    int t[21][10003];
    int dfs(int index, int diff, vector<int>& rods){
        
        if(index >= rods.size()){
            if(diff == 0)
                return 0;
            
            return INT_MIN;
        }
        /*
        l1 - l2 = diff
        
        (l1 + x) - l2 => l1 - l2 + x => diff + x
        
        l1 - (l2 + x) => l1 - l2 - x => diff - x
        */
        
        if(t[index][diff + 5000] != -1)
            return t[index][diff + 5000];
        
        int not_taken = dfs(index+1, diff, rods);
        
        int for_left_rod = rods[index] + dfs(index+1, diff + rods[index], rods);
        
        int for_right_rod = rods[index] + dfs(index+1, diff - rods[index], rods);
        
        return t[index][diff + 5000] = max({not_taken, for_left_rod, for_right_rod});
    }
    
    int tallestBillboard(vector<int>& rods) {
        
        //return dfs(0, 0, 0, rods);
        memset(t, -1, sizeof t);
        return dfs(0, 0, rods) / 2; 
    }
};