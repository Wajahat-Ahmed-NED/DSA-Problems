async function retryRequest(fn, retries = 3, delay = 500) {
    try {
        return await fn();
    } catch (err) {
        if (retries === 0) throw err;

        console.log(`Retrying... attempts left: ${retries}`);

        await new Promise(res => setTimeout(res, delay));

        return retryRequest(fn, retries - 1, delay * 2); // exponential backoff
    }
}


const axios = require("axios");

async function callAPI() {
    return axios.get("https://example.com/api");
}

retryRequest(callAPI, 3)
    .then(res => console.log("Success:", res.data))
    .catch(err => console.error("Failed:", err.message));
