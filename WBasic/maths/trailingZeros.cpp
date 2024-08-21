// https://leetcode.com/problems/factorial-trailing-zeroes/


// No.s of 5 will give no of zeros in the factorial of that number;
// 5!=120; 5x4x3x2x1 => (has 1 5)
// 10!=10900; 10x9x8x7x6x5x4x3x2x1 => (has 1->5, 10 = (2x5) -> has 2->5's) //dummy

// dividing by 5 will give no of 5's in 100;
// dividing by 25(5x5) will give no of 25's in 100;
// dividing by 125(5x5x5) will give no of 25's in 100;
// ... so on

// Remember this series:
// [n/5 + n/5^2 + n/5^3 + n/5^4 + ... ]
// if n=100 then 
// [20 + 4 + 100/125 = 0.7=0+ ... ] = 24 0's in 100!

int trailingZeros(n){
    int count=0;
    while(n>=5){
        n/=5;
        count+=n;
    }
    return count;
}