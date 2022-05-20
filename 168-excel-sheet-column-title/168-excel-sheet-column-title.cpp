class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result="";

        while(columnNumber != 0){
            columnNumber--;
            
            int temp = columnNumber % 26;
            result += (char)(65 + temp); //A->65 ascii code
            columnNumber /= 26;
        }

        reverse(result.begin(), result.end());
        return result;
        
    }
};