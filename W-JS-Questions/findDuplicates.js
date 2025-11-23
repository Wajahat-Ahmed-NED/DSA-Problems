

function findDuplicates(arr) {
    // const seen = new Set();
    const map = new Map();
    const duplicates = [];

    for (const i of arr) {
        if (map.has(i)) duplicates.push(i);
        else map.set(i, true)
    }

    return duplicates;
}


console.log(findDuplicates([1, 3, 4, 3, 2, 1, 32, 4, 5]))