/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let m={}
    let count=0;

    let mini=Number.MAX_SAFE_INTEGER
    let maxi=0;

    for(let i of nums){
        m[i]++;
        mini=Math.min(mini,i);        
    }

    let arr=Object.keys(m).map(x=>x-0).sort((a,b)=>a-b)
    console.log(arr)

    for(let i of arr){
        if(i==mini){
        console.log(i," ",mini);
            count++;
            mini++;
        }
        else{
            count=1;
            mini=i+1;
        }

        maxi=Math.max(maxi,count);
    }

    return maxi;
};