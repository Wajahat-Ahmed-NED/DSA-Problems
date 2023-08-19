// Source: Coding Ninjas
// completely solve nhi hoa
// link: https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_10

#include <bits/stdc++.h> 
int countDistinctWays(int n) {
    //  Write your code here.
    if (n<0){
        return 0;
    }
    if (n==0){
        return 1;
    }

    return countDistinctWays(n-1)+countDistinctWays(n-2);
}