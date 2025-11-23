

// function memoize(...args) {
//     const map = new Map();

//     const key = JSON.stringify(args);

//     if (map.has(key)) return map[key];

//     const result = add(args[0], args[1]);
//     map.set(key, result);
//     return result;
// }

const add = (a, b) => a + b;

const memoize = (computeFunction) => {
    const cache = new Map(); // can also use weakmap for memory efficiency

    return function (...args) {
        const key = JSON.stringify(args);

        if (cache.has(key)) {
            console.log("Fetching from cache for args " + cache.get(key));
            return cache.get(key);
        }

        const result = computeFunction(...args);
        console.log("Computing result " + result);
        cache.set(key, result);
        return result;
    }
}


const memoizedAdd = memoize(add);

console.log(memoizedAdd(2, 4));
console.log(memoizedAdd(2, 4));
console.log(memoizedAdd(3, 5));
console.log(memoizedAdd(3, 5));