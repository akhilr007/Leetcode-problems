class Solution{
public:

    int findgcd(int a, int b){

        if(b == 0) return a;

        return findgcd(b, a%b);
    }

    string getSlope(vector<int>& p1, vector<int>& p2){

        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];

        // if 2 4 and 1 2
        int gcd = findgcd(x, y);
        if(x!=0 || y!=0){
            x = (gcd == 0 ? x / max(x, y) : x / gcd);
            y = (gcd == 0 ? y / max(x, y) : y / gcd);
        }

        string slope="";
        slope = to_string(x) + "/" + to_string(y);
        return slope;

    }

    int maxPoints(vector<vector<int>>& points) {
        
        // edge case if only two points are given
        if(points.size() < 3){
            return points.size();
        }

        int maxPointsOnALine=2;

        for(int i=0; i<points.size()-1; i++){
            unordered_map<string, int> lineCount;
            for(int j=1; j<points.size(); j++){
                string slope = getSlope(points[i], points[j]);
                lineCount[slope]++;
            }

            for(auto it : lineCount){
                maxPointsOnALine = max(maxPointsOnALine, lineCount[it.first] + 1);
            }
        }

        return maxPointsOnALine;
    }
};