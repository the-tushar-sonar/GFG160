#include <bits/stdc++.h>
using namespace std;

// Brute Force => O(n*m)
vector<int> search(string &pat, string &txt)
{
    vector<int> result;

    for (int i = 0; i < txt.size(); i++)
    {
        int count = 0;

        if (i > (txt.size() - pat.size()))
            break;

        // cout << "Starting from text index i = " << i << endl;

        for (int j = 0; j < pat.size(); j++)
        {
            // cout << "i = " << i
            //      << ", j = " << j
            //      << " | txt[" << i + j << "] = '" << txt[i + j] << "'"
            //      << " | pat[" << j << "] = '" << pat[j] << "'";

            if (txt[i + j] == pat[j])
            {
                count++;
                // cout << " -> MATCH"
                //      << " | count = " << count << endl;
            }
            else
            {
                // cout << " -> NOT MATCH"
                //      << " | count = " << count << endl;

                break;
            }
        }

        if (count == pat.size())
        {
            // cout << ">> PATTERN FOUND at index " << i << endl;

            result.push_back(i);
        }
    }

    // cout << "\nFinal result: ";

    // for (int num : result)
    // {
    //     cout << num << " ";
    // }

    // cout << endl;
    return result;
}
int main()
{
    // string txt = "aacabdc";
    // string pat = "aab";
    // string txt = "geeksforgeeks";
    // string pat = "geek";
    string txt = "aaaaa";
    string pat = "aa";

    vector<int> ans = search(pat, txt);

    for (int n : ans)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}