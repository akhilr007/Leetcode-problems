class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // 1. calculate prefix sum for all rows
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        unordered_map<int, int> counter;
        //2. accumulate all sum for columns
        int res=0;
        for(int c1=0; c1<m; c1++){
            for(int c2=c1; c2<m; c2++){
                
                counter.clear();
                counter[0] = 1;
                int cur_sum=0;
                
                for(int r=0; r<n; r++){
                    cur_sum += matrix[r][c2] - (c1>0 ? matrix[r][c1-1] : 0);
                    if(counter.find(cur_sum-target) != counter.end()){
                        res += counter[cur_sum-target];
                    }
                    else res += 0;
                    counter[cur_sum]++;
                }
                
            }
        }
        
        return res;
    }
};