

function reverseString(str) {
    //Strings are immutable in js so convert to arr first
    const arr = str.split("");
    let s = 0; let e = arr.length - 1;
    while (s < e) {
        let temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;

        // console.log(s, " ", e)

        s++;
        e--;
    }
    // console.log(arr)
    return arr.join("");
}

console.log(reverseString("wajahat"))