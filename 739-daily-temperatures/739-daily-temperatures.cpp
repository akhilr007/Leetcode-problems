class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        vector<int> output(temperatures.size());
        
        for(int i=temperatures.size()-1; i>=0; i--){
            
            while(st.size() > 0 && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            
            if(st.size()==0){
                output[i] = 0;
            }
            else{
                output[i] = st.top()-i;
            }
            st.push(i);
        }
        
        return output;
    }
};