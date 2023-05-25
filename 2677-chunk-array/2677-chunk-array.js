/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
const chunk = function(arr, size) {
    
    const chunked_array = [];
    let index = 0;
    
    while(index < arr.length){
        
        let count = size;
        const temp = [];
        
        while(count-- > 0 && index < arr.length){
            
            temp.push(arr[index]);
            index++;
        }
        
        chunked_array.push(temp);
    }
    return chunked_array;
};
