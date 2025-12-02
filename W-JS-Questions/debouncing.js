

const debounce = (fn, delay) => {
    let timerId;

    return (...args) => {
        clearInterval(timerId);
        timerId = setTimeout(() => {
            fn(...args)
        }, delay);
    }
}

const search = (...args) => {
    console.log("searching values ", ...args)
}


const searchWithDebounce = debounce(search, 1000);

searchWithDebounce("Hi ")
searchWithDebounce("Hi Wajahat ")
searchWithDebounce("Hi here")
searchWithDebounce("Hi Wajahat here")