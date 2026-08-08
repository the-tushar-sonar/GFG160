#include <bits/stdc++.h>
#include <climits>
using namespace std;

int myAtoi(string s)
{
    int sign = 1;
    int ans = 0;
    int idx = 0;

    // Ignore leading whitespaces
    while (idx < s.size() && s[idx] == ' ')
        idx++;

    // Store the sign of number
    if (idx < s.size() && (s[idx] == '-' || s[idx] == '+'))
    {
        if (s[idx] == '-')
            sign = -1;

        idx++;
    }

    // Construct the number digit by digit
    while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9')
    {
        int digit = s[idx]-'0';

        // handling overflow/underflow
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        // Append current digit to the answer
        ans = 10 * ans + digit;

        idx++;
    }
    return ans * sign;
}

struct TestCase
{
    string s;
    int expected;
};

int main()
{
    // string s = "  -123";
    // int ans = MyAtoi(s);
    // cout << ans << "\n";

    vector<TestCase> testCases =
        {
            {"123", 123},
            {"-123", -123},
            {"+123", 123},
            {"   123", 123},
            {"   -123", -123},

            {"000123", 123},
            {"-000123", -123},
            {"+000123", 123},

            {"123abc", 123},
            {"-123abc", -123},
            {"123.45", 123},

            {"abc123", 0},
            {"+", 0},
            {"-", 0},

            {"++123", 0},
            {"--123", 0},
            {"+-123", 0},
            {"-+123", 0},

            {"2147483647", INT_MAX},
            {"2147483648", INT_MAX},

            {"-2147483648", INT_MIN},
            {"-2147483649", INT_MIN},

            {"999999999999", INT_MAX},
            {"-999999999999", INT_MIN},

            {"  -0012gfg4", -12},
            {"4193 with words", 4193},
            {"words and 987", 0}};

    for (const auto &test : testCases)
    {
        int result = myAtoi(test.s);

        if (result == test.expected)
            cout << "PASS\n";
        else
            cout << "FAIL | Input: \"" << test.s
                 << "\" | Expected: " << test.expected
                 << " | Got: " << result << '\n';
    }

    return 0;
}