class Solution {
private:
    // using two stacks
    bool checkValidStringUsingStack(string s) {
        
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
    
public:
    bool checkValidString(string s) {
        
        // leftMin -> min open brackets 
        // leftMax -> max open brackets
        int leftMin=0, leftMax=0;
        
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == '('){
                leftMin++, leftMax++;
            }
            else if(s[i] == ')'){
                leftMin--, leftMax--;
            }
            else{
                leftMin--;
                leftMax++;
            }
            
            if(leftMin<0) leftMin = 0;
            if(leftMax<0) return false;
        }
        
        return leftMin==0;
        
    }  
};