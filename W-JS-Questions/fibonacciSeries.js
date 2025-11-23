// Recursive approach takes TC O(2^n) and SC O(n)
// Iterative approach takes TC O(n) and SC O(1)
function fibonacciSeries(n) {
    let first = 0;
    let second = 1;
    const series = [];
    series.push(first);
    series.push(second);

    for (let i = 0; i < n; i++) {
        let temp = first + second;
        first = second;
        second = temp;
        series.push(second);
    }


    return series;
}

console.log(fibonacciSeries(10));


function fibonacciRecursive(n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}


console.log(fibonacciRecursive(10));