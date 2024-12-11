class Solution
{
public:
    bool armstrongNumber(int n)
    {
        int power = 0;
        int num = n;
        while (num != 0)
        {
            power++;
            num = num / 10;
        }

        int sum = 0;
        num = n;

        while (num != 0)
        {

            int digit = num % 10;
            sum += pow(digit, power);
            num = num / 10;
        }

        return sum == n;
    }
};