/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function(points) {
    
    points.sort(function(a, b){
        return a[0] - b[0];
    });
    
    let prev = points[0]
    
    let count = 1;
    for(let i=1; i<points.length; i++){
        
        let curStartPoint = points[i][0];
        let curEndPoint = points[i][1];
        
        let prevStartPoint = prev[0];
        let prevEndPoint = prev[1];
        
        if(curStartPoint > prevEndPoint){
            // no overlap
            count++;
            prev = points[i];
        }
        else{
            prev[0] = Math.max(prev[0], curStartPoint);
            prev[1] = Math.min(prev[1], curEndPoint);
        }
    }
    
    return count;
};