class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int res = INT_MIN;
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        for(int l=0; l<cols; l++)
        {
            vector<int> sums(rows);
            for(int r=l; r<cols; r++)
            {
                for(int i=0; i<rows; i++)
                {
                    sums[i] += matrix[i][r];
                }
                
                set<int> s = {0};
                int cum_sum = 0;
                
                for(int sum : sums) 
                {
                    cum_sum += sum;
                    
                    auto it = s.lower_bound(cum_sum - k);
                
                    if(it != s.end()) res = max(res, cum_sum - *it);
                    s.insert(cum_sum);
                }
            }
        }
        
        return res;
    }
};