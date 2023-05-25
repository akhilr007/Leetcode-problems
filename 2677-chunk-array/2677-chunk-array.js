/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
const chunk = function(arr, size) {
    
    const chunked_array = [];
    let index = 0;
    
    while(index < arr.length){
        
        chunked_array.push(arr.slice(index, index+size));
        index += size;
    }
    return chunked_array;
};
