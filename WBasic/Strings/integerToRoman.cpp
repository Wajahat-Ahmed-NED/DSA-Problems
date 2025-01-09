// Optimized Approach

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> romanToInt = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

        string romanForm = "";
        int ind = 0;
        int n = romanToInt.size();

        while (num != 0)
        {
            if (num < romanToInt[ind].first)
                ind++;
            else
            {
                num -= romanToInt[ind].first;
                romanForm += romanToInt[ind].second;
            }
        }

        return romanForm;
    }
};

// Brute Force Approach

class Solution
{
public:
    string intToRoman(int num)
    {
        string ans = "";
        unordered_map<int, char> intToRoman;
        intToRoman[1] = 'I';
        intToRoman[5] = 'V';
        intToRoman[10] = 'X';
        intToRoman[50] = 'L';
        intToRoman[100] = 'C';
        intToRoman[500] = 'D';
        intToRoman[1000] = 'M';

        unordered_map<int, string> subIntToRoman;
        subIntToRoman[4] = "IV";
        subIntToRoman[9] = "IX";
        subIntToRoman[40] = "XL";
        subIntToRoman[90] = "XC";
        subIntToRoman[400] = "CD";
        subIntToRoman[900] = "CM";

        vector<int> arr = {1000, 500, 100, 50, 10, 5, 1};

        int cntZeros = 1;

        while (num != 0)
        {
            int digit = num % 10;
            digit = digit * cntZeros;
            cntZeros = cntZeros * 10;
            int i = 0;
            if (subIntToRoman.find(digit) != subIntToRoman.end())
            {
                ans = subIntToRoman[digit] + ans;
            }
            else
            {
                string prod = "";
                i = 0;
                while (digit != 0)
                {

                    while (i < arr.size() && digit / arr[i] <= 0)
                        i++;

                    int quotient = digit / arr[i];
                    int rem = digit % arr[i];

                    cout << i << " ";
                    int k = 0;
                    while (k < quotient)
                    {
                        prod = prod + intToRoman[arr[i]];
                        k++;
                    }

                    digit = rem;
                }
                ans = prod + ans;
                cout << endl;
            }

            num = num / 10;
        }

        return ans;
    }
};