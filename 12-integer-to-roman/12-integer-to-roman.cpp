class Solution {
public:
    string intToRoman(int num) {
        
        // 1 : "I", 5 : "V", 10:"X", 50:"L", 100:"C", 500:"D", 1000:"M"
        
        string units[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};
        
        string res;
        res = thousands[num/1000] + hundreds[(num%1000)/100] + tens[(num%100)/10] + units[num%10];
        return res;
    }
};