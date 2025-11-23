// Maximum Sub Array sum


function maxSubArraySum(arr) {
    let maxTillNow = -Infinity;
    let currSum = 0;

    for (let i = 0; i < arr.length; i++) {
        currSum += arr[i];
        maxTillNow = Math.max(currSum, maxTillNow);

        if (currSum < 0) currSum = 0;
    }

    return maxTillNow;

}


console.log(maxSubArraySum([1, -2, 3, 4, -1, 2]))