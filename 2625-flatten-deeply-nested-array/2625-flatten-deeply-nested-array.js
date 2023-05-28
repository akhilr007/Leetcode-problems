/**
 * @param {any[]} arr
 * @param {number} depth
 * @return {any[]}
 */
const flat = function (arr, n) {
    
    let res = [];
    
    function flattening(nums, l){
        
        for(let num of nums){
            if(Array.isArray(num) && l > 0){
                flattening(num, l-1);
            }
            else{
                res.push(num);
            }
        }
    }
    
    flattening(arr, n);
    return res;
};