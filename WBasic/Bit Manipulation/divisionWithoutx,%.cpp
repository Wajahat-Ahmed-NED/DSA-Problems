class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long num = abs((long long)dividend);
        long long denom = abs((long long)divisor);
        int sign = (dividend < 0) ^ (divisor < 0);
        long long quotient = 0;
        while (num >= denom)
        {
            int times = 0;
            while (num >= denom << times)
            {
                times++;
            }

            times--;
            quotient += 1LL << times;
            num -= denom << times;
        }

        if (quotient > INT_MAX)
        {
            if (sign == 1)
                return INT_MIN;
            return INT_MAX;
        }

        return sign == 0 ? quotient : -1 * quotient;
    }
};