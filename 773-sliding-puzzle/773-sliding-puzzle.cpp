class Solution {
public:
    int findZeroIndex(string& s){

        for(int i=0; i<s.length(); i++){
            if(s[i] == '0'){
                return i;
            }
        }
        return -1;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        
        string initial = "";
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                initial += to_string(board[i][j]);
            }
        }

        string target = "123450";
        vector<vector<int>> swapidx = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        unordered_set<string> visited;
        int level=-1;

        queue<string> q;
        q.push(initial);

        while(q.size() > 0){
            int size = q.size();
            level++;

            while(size-->0){

                auto rem = q.front();
                q.pop();

                if(rem == target) return level;

                // find idx of zero
                int idx = findZeroIndex(rem);
                vector<int> swapPos = swapidx[idx];

                for(int i=0; i<swapPos.size(); i++){
                    string temp = rem;
                    swap(temp[idx], temp[swapPos[i]]);

                    if(visited.find(temp) != visited.end()){
                        continue;
                    }
                    
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }

        return -1;
    }
};