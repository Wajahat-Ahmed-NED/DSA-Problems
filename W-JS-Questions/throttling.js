// slow down the hits 
// like youtube live comments get disable after commenting


const throttle = (fn, delay) => {
    let lastTime = 0;

    return (...args) => {
        const now = new Date();
        if (now - lastTime < delay) return
        lastTime = now;
        return fn(...args)
    }
}

const search = (...args) => {
    console.log("Searching ", ...args)
}

const searchSlowMode = throttle(search, 1000);

searchSlowMode("Hi wajahat")
searchSlowMode("Hi wajahat2")
searchSlowMode("Hi wajahat3")


setTimeout(() => searchSlowMode("Hi wajahat4"), 2000)