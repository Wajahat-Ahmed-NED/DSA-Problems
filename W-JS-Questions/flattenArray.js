const nestedArr = [1, [2, [3, [4]]], 5];



function flattenArray(arr) {
    const result = [];
    for (const i of arr) {
        if (Array.isArray(i)) {
            result.push(...flattenArray(i));
        }
        else {
            result.push(i);
        }
    }
    return result;
}

function flattenArrayUsingReduce(arr) {

    const result = arr.reduce((prev, curr) => {
        if (Array.isArray(curr)) {
            const flattened = flattenArrayUsingReduce(curr);
            prev.push(...flattened);
        }
        else {
            prev.push(curr);
        }
        return prev;
    }, [])

    return result;

}

// console.log(flattenArray(nestedArr))
console.log(flattenArrayUsingReduce(nestedArr))