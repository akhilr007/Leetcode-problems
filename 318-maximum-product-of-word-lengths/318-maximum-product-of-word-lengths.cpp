class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int len = words.size();
        vector<int> state(len);
        
        for(int i=0; i<len; i++){
            state[i] = getStateFromString(words[i]);
        }
        
        int maxProduct=0;
        for(int i=0; i<len; i++){
            for(int j=i+1; j<len; j++){
                if((state[i]&state[j]) == 0){
                    int product = words[i].length() * words[j].length();
                    if( product > maxProduct){
                        maxProduct = product;
                    }
                }
            }
        }
        
        return maxProduct;
    }
private:
    int getStateFromString(string s){
        
        int state=0;
        for(char ch : s){
            
            int index  = ch - 'a';
            state = state | (1 << (index));
        }
        
        return state;
    }
};