class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        unordered_map<char, string> morseCode;
        morseCode['a'] = ".-";
        morseCode['b'] = "-...";
        morseCode['c'] = "-.-.";
        morseCode['d'] = "-..";
        morseCode['e'] = ".";
        morseCode['f'] = "..-.";
        morseCode['g'] = "--.";
        morseCode['h'] = "....";
        morseCode['i'] = "..";
        morseCode['j'] = ".---";
        morseCode['k'] = "-.-";
        morseCode['l'] = ".-..";
        morseCode['m'] = "--";
        morseCode['n'] = "-.";
        morseCode['o'] = "---";
        morseCode['p'] = ".--.";
        morseCode['q'] = "--.-";
        morseCode['r'] = ".-.";
        morseCode['s'] = "...";
        morseCode['t'] = "-";
        morseCode['u'] = "..-";
        morseCode['v'] = "...-";
        morseCode['w'] = ".--";
        morseCode['x'] = "-..-";
        morseCode['y'] = "-.--";
        morseCode['z'] = "--..";
        
        unordered_map<string, int> codeTransformation;
        for(int i=0; i<words.size(); i++){
            string str = "";
            for(int j=0; j<words[i].length(); j++){
                str += morseCode[words[i][j]];
            }
            codeTransformation[str]++;
        }
        
        return codeTransformation.size();
    }
};