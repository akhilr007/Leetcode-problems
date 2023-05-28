Array.prototype.last = function() {
    const arr = this;
    if(arr.length === 0)
        return -1;
    
    return arr[arr.length-1];
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */