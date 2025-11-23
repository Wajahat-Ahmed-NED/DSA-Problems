

function isBalancedParanthesis(str) {
    const stack = [];
    const pairs = { '{': '}', '[': ']', '(': ')' }

    for (const char of str) {
        if (pairs[char]) {
            stack.push(char)
        }
        else if (Object.values(pairs).includes(char)) {
            if (pairs[stack.pop()] !== char) {
                return false;
            }
        }
        else return false;
    }

    return stack.length === 0;
}


console.log(isBalancedParanthesis("{)()]}"))