class Solution {
public:
    bool search(vector<vector<char>>& board, int i, int j, int index, string& word){
        
        if(index == word.size()) return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '*') return false;
        
        if(board[i][j] != word[index]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool res = search(board, i-1, j, index+1, word) ||
                    search(board, i, j-1, index+1, word) ||
                    search(board, i+1, j, index+1, word) ||
                    search(board, i, j+1, index+1, word);
        
        board[i][j] = temp;
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(search(board, i, j, 0, word)) return true;
            }
        }
        
        return false;
    }
};