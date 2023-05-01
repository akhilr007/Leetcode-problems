class Solution {
public:
    double average(vector<int>& salary) {
        
        sort(begin(salary), end(salary));
        
        int sum = 0;
        int cnt = 0;
        for(int i=1; i<salary.size()-1; i++)
        {
            sum += salary[i];
            cnt ++;
        }
        
        
        double average = (sum * 1.0) / cnt;
        
        return average;
    }
};