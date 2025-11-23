


// Given an array of users, return only active users sorted by age.
function filterAndSortActiveUsers(users) {
    return users
        .filter(user => user.isActive)
        .sort((a, b) => a.age - b.age);
}

const usersJson = [{ name: "Alice", age: 30, isActive: true },
{ name: "Bob", age: 25, isActive: false },
{ name: "Charlie", age: 35, isActive: true },
{ name: "David", age: 20, isActive: true }];

console.log(filterAndSortActiveUsers(usersJson));



// Given JSON input, return all product names whose price < 500.
const cheapProduct = (products) => {
    return products.filter(p => p.price < 500).map(p => p.name)
        // .sort((a, b) => b.localeCompare(a)); // For descending order
        .sort((a, b) => a.localeCompare(b)); // For ascending order
}

const productsJson = [
    { name: "Laptop", price: 1000 },
    { name: "Smartphone", price: 300 },
    { name: "Tablet", price: 450 },
    { name: "Monitor", price: 600 }
];

console.log(cheapProduct(productsJson));



// Flatten nested array
function flatten(arr) {
    return arr.flat(Infinity); // Must practice via recursion also
}

const nestedArray = [1, [2, [3, [4]], 5], 6];

console.log(flatten(nestedArray)); // Must practice via recursion also



// Count frequency of characters
function frequencyCounter(str) {
    const freq = {};

    for (char of str) {
        freq[char] = (freq[char] || 0) + 1;
    }

    return freq;
}



// Given an API response, return only the titles of completed todos
async function getCompletedTodosTitles() {
    const response = await fetch('https://jsonplaceholder.typicode.com/todos')
    const todos = await response.json();
    return todos.filter(todo => todo.completed).map(todo => todo.title);
}

getCompletedTodosTitles().then(response => console.log(response));
// console.log(todosList);


