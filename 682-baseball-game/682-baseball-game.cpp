class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> st;
        
        for(int i=0; i<ops.size(); i++){
            
            if(ops[i] != "C" && ops[i] != "D" && ops[i] != "+"){
                
                int val = stoi(ops[i]);
                st.push(val);
            }
            
            else if(ops[i] == "C"){
                st.pop();
            }
            
            else if(ops[i] == "D"){
                int val = st.top();
                val = 2*val;
                st.push(val);
            }
            
            else if(ops[i] == "+"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                int sum = a+b;
                st.push(b);
                st.push(a);
                st.push(sum);
            }
        }
        
        int sum=0;
        while(st.size()>0){
            int val = st.top();st.pop();
            sum += val;
        }
        
        return sum;
    }
};