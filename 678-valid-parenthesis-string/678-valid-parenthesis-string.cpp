class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> star;
        stack<int> pair;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == '('){
                pair.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!pair.empty()){
                    pair.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        
        return isBalanced(star, pair);
    }
    
    bool isBalanced(stack<int>& star, stack<int>& pair){
        
        while(!pair.empty()){
            
            if(star.empty()) return false;
            
            // using star as )
            else if(star.top() > pair.top()){
                star.pop();
                pair.pop();
            }
            else{
                return false;
            }
        }
        
        return true;
    }
};