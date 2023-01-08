class Solution {
private:
    int bruteForce(vector<vector<int>>& points){
        
        int n = points.size();
        if(n == 1) return 1;
        
        int maxPoint = 0;
        
        for(int i=0; i<n; i++){ // p1 (x1, y1)
            
            for(int j=i+1; j<n; j++){ // p2(x2, y2)
                
                int count = 2;
                
                int dx = points[j][0] - points[i][0]; // (x2-x1)
                int dy = points[j][1] - points[i][1]; // (y2-y1)
                
                /*
                    dy/dx = dy_/dx_
                    dy*dx_ = dy_*dx
                */
                
                for(int k=0; k<n; k++) { // p3(x3, y3)
                    
                    if(k != i && k != j){
                        
                        int dx_ = points[k][0] - points[i][0]; // (x3-x1)
                        int dy_ = points[k][1] - points[i][1]; // (y3-y1)
                        
                        if(dy*dx_ == dy_*dx) count++;
                    }
                }
                
                maxPoint = max(maxPoint, count);
            }
        }
        
        return maxPoint;
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        return bruteForce(points);
    }
};