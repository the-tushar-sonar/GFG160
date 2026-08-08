#include <bits/stdc++.h>
#include <climits>
using namespace std;

int MyAtoi(string s)
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
        if (idx == '-')
            sign = -1;
        idx++;
    }

    // Construct the number digit by digit
    while (idx < s.size() && '0' <= s[idx] <= '9')
    {
        // Append current digit to the answer
        ans = 10 * ans + (s[idx] - '0');

        // handling overflow/underflow
        if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[idx] - '0' > 7))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        idx++;
    }
    return ans * sign;
}

int main()
{

    string s = "  -123";
    int ans = MyAtoi(s);
    cout << ans << "\n";

    return 0;
}