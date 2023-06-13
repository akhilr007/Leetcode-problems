class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int equalPairs = 0;
        
        vector<vector<int>> rows;
        vector<vector<int>> cols;
        
        for(auto row: grid)
            rows.push_back(row);
        
        for(int col=0; col<grid.size(); col++){
            vector<int> temp;
            for(int row=0; row<grid.size(); row++){
                
                temp.push_back(grid[row][col]);
            }
            cols.push_back(temp);
        }
        
        for(auto r : rows)
        {
            for(auto i: r)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        
        for(auto r : cols)
        {
            for(auto i: r)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        
        for(int i=0; i<grid.size(); i++){
            
            for(int j=0; j<grid.size(); j++){
                
                if(rows[i] == cols[j])
                    equalPairs++;
            }
        }
        return equalPairs;
    }
};