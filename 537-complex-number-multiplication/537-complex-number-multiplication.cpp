class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        
        // after multiplying two complex numbers we get
        // (a*c - b*d) + (a*d + b*c)i
        
        int i1 = num1.find('+');
        int a = stoi(num1.substr(0, i1)); // real part of num1
        int b = stoi(num1.substr(i1+1, num1.size()-i1-2)); // imaginary part of num1
        
        int i2 = num2.find('+');
        int c = stoi(num2.substr(0, i2)); // real part of num2
        int d = stoi(num2.substr(i2+1, num2.size()-i2-2)); // imaginary part of num2
        
        string res="";
        res = to_string(a*c - b*d) + "+" + to_string(a*d + b*c) + "i";
        return res;
        
    }
};