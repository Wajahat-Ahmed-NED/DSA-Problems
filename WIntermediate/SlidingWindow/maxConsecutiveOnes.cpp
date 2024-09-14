class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                zeroCount++;
            }

            while (zeroCount > k)
            {
                if (nums[l] == 0)
                    zeroCount--;
                l++;
            }

            // if(zeroCount>k){
            //     l=secondZeroInd;
            //     secondZeroInd=r;
            //     zeroCount=k;
            // }

            maxLength = max(maxLength, r - l + 1);
            r++;
        }

        return maxLength;
    }
};

// More Optimized

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, r = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while (r < nums.size())
        {

            if (nums[r] == 0)
            {
                zeroCount++;
            }

            if (zeroCount > k)
            {
                if (nums[l] == 0)
                    zeroCount--;
                l++;
            }

            if (zeroCount <= k)
                maxLength = max(maxLength, r - l + 1);
            r++;
        }

        return maxLength;
    }
};