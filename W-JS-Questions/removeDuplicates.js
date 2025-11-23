// function removeDuplicates(arr) {
//     return [...new Set(arr)]
// }


function removeDuplicates(arr) {
    const map = new Map();
    const filteredArray = [];

    for (const char of arr) {
        if (!map.has(char)) filteredArray.push(char)
    }

    return filteredArray
}

console.log(removeDuplicates([1, 2, 2, 3, 4, 4])); 