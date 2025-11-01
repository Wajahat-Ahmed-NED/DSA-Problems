// Online Javascript Editor for free
// Write, Edit and Run your Javascript code using JS Online Compiler

console.log("Try programiz.pro");

function isUpperCase(char) {
    return char == = char.toUpperCase() && char != = char.toLowerCase();
}

const str = ["r", "sw", "x", "c", "nm", "q", "yt", "z", "ab"]
const operation = 1 // encoding;
const input = "Cat"                                                             //"bat";
let result = "";

const mapping = new Map();

str.map((e, i) = > {
    for(let x = 0; x<e.length; x++)
{
    mapping[e[x]] = [i + 1, x + 1];
}
})

if (operation == 1) { // encoding
    for (let i = 0; i < input.length; i++) {
        const position = mapping[input[i]];
        if (!position) {
            console.log("Error here ")
            result = "Error";
            break;
        }
        if (isUpperCase(input[i])) result += '0'
        result += (position[0].toString()).repeat(position[1]);
        result += '0';
    }
}
else if (operation == 2) {
    let isCapital = false;
    let i = 0;
    while (i < input.length) {
        if (input[i] == '0') {
            isCapital = true;
            i++;
            continue;
        }

        let occurrence = 1;
        let j = i;
        while (j + 1 < input.length && input[j] == input[j + 1]) {
            occurrence++;
            j++;
        }

        let ind = parseInt(input[i]) - 1;
        if (ind >= str.length) {
            result = "Error";
            break;
        }
        let actualString = str[parseInt(input[i]) - 1];
        if (occurrence - 1 >= actualString) {
            result = "Error";
            break;
        }
        const position = actualString[occurrence - 1];

        i = j + 1;

        if (input[i] == '0') {
            i++;
        }

        result += isCapital ? position.toUpperCase() : position;

        isCapital = false;
    }
}

console.log(result);
