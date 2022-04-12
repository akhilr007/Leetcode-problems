class Solution {
private:
    int dir[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
public:
    int getActiveNeighbour(vector<vector<int>>& board, int i, int j){
        
        int activeNbr=0;
        
        for(int R=0; R<8; R++){
            int r = i + dir[R][0];
            int c = j + dir[R][1];
            
            if(r >= 0 && c >= 0 && r < board.size() && c < board[0].size() && (board[r][c] == 1 || board[r][c] == -2)){
                activeNbr++;
            }
        }
        
        return activeNbr;
    }
    
    void updateBoard(vector<vector<int>>& board){
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                
                if(board[i][j] == -2){
                    board[i][j] = 0;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(board[i][j] == 1){
                    int activeNbr = getActiveNeighbour(board, i, j);
                    if(activeNbr < 2 || activeNbr > 3){
                        board[i][j] = -2; // 0
                    }
                }
                else if(board[i][j] == 0){
                    int activeNbr = getActiveNeighbour(board, i, j);
                    if(activeNbr == 3){
                        board[i][j] = 3; // 1
                    }
                }
            }
        }
        
        updateBoard(board);
        return;
    }
};