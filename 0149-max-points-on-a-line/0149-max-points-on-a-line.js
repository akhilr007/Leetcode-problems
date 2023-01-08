/**
 * @param {number[][]} points
 * @return {number}
 */
function findGCD(a, b) {
    
    if( b == 0) return a;
    
    return findGCD(b, a % b);
}

var maxPoints = function(points) {
    
    let n = points.length;
    
    if(n == 1)
        return 1;
    
    let result = 0;
    
    for(let i=0; i<n; i++){
        
        let freq = new Map();
        
        for(let j=0; j<n; j++){
            
            if(i == j) continue;
            
            let dx = points[j][0] - points[i][0];
            let dy = points[j][1] - points[i][1];
            
            let gcd = findGCD(Math.max(dx, dy), Math.min(dx, dy));
            
            let key = (dx / gcd) + "_" + (dy / gcd);
            
            if(freq.has(key) == false){
                freq.set(key, 1);
            }
            else{
                freq.set(key, freq.get(key) + 1);
            }
        }
        
        freq.forEach((value, key) => {
            result = Math.max(result, value + 1);
        })
    }
    
    return result;
};