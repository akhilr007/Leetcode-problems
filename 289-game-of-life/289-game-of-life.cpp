class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        // top left down right top-dia-left top-dia-right bott-dia-left bott-dia-right
        int dir[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        vector<vector<int>> res(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int life=0;
                
                if(board[i][j] == 1){
                    
                    for(int k=0; k<8; k++){
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        
                        if(r >=0 && c >= 0 && r < board.size() && c < board[0].size()){
                            if(board[r][c] == 1){
                                life++;
                            }
                        }
                    }
                    
                    if(life < 2) res[i][j]=0;
                    else if(life == 2 || life == 3) res[i][j] = 1;
                    else if(life > 3) res[i][j] = 0;
                    
                }
                else{
                    
                    for(int k=0; k<8; k++){
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        
                        if(r >=0 && c >= 0 && r < board.size() && c < board[0].size()){
                            if(board[r][c] == 1){
                                life++;
                            }
                        }
                    }
                    
                    if(life == 3) res[i][j] = 1;
                }
            }
        }
        
        board = res;
    }
};