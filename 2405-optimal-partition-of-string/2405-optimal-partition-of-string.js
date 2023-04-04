/**
 * @param {string} s
 * @return {number}
 */
var partitionString = function(s) {
    
    const set = new Set();
    const n = s.length;
    
    let i=0;
    let cnt=0;
    
    while(i<n){
        
        if(set.has(s[i])){
            cnt++;
            set.clear();
            continue;
        }
        
        set.add(s[i]);
        i++;
    }
    
    if(set.size) cnt++;
    return cnt;
};