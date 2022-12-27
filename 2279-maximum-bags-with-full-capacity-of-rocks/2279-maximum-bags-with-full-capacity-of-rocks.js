var maximumBags = function(capacity, rocks, additionalRocks) {
    
    let n = rocks.length;
    
    let required_rocks = [];
    
    for(let i=0; i<n; i++){
        let current_rock = rocks[i];
        let capacity_rock = capacity[i];
        required_rocks.push(capacity_rock - current_rock);
    }
    
    required_rocks.sort((a, b) => a - b);
    
    let count=0;
    for(let i=0; i<n; i++){
        if(additionalRocks >= required_rocks[i]){
            additionalRocks -= required_rocks[i];
            count++;
        }
        else break;
    }
    
    return count;
};