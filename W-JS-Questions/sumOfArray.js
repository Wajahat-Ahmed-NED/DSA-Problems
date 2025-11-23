function findSumArray(arr) {
    return arr.reduce((prev, curr) => prev + curr, 0)
}

console.log(findSumArray([1, 2, 3, 4, 5]))