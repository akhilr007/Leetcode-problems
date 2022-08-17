class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_map<string, int> codeTransformation;
        for(auto word : words){
            string str = "";
            for(auto ch : word){
                str += codes[ch-'a'];
            }
            codeTransformation[str]++;
        }
        
        return codeTransformation.size();
    }
};