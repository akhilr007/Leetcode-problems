class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        set<string> s;
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                
                char ch = board[i][j];
                
                if(ch != '.'){
                    
                    string no="";
                    no +=ch;

                    string ith = to_string(i);
                    string jth = to_string(j);


                    if(s.find(no + "_R_" + ith) != s.end() || 
                      s.find(no + "_C_" + jth) != s.end() ||
                      s.find(no + "_B_" + to_string(i/3) + to_string(j/3)) != s.end()) return false;

                    else{
                        s.insert(no + "_R_" + ith);
                        s.insert(no + "_C_" + jth);
                        s.insert(no + "_B_" + to_string(i/3) + to_string(j/3));
                    }
                }
            }
        }
        
        return true;
    }
};