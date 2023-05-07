/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
const createCounter = function(init) {
    
    let val = init;
    
    return {
        
        increment: function increment(){
            return ++val;
        },
    
        decrement: function decrement(){
            return --val;
        }
        
        ,
        
        reset: function reset(){
            val = init;
            return val;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */