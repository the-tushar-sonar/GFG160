#include <bits/stdc++.h>
using namespace std;

/*
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
*/

// Using KMP Algorithm & LPS => O(n+m)
void constructLps(string &pat, vector<int> &lps)
{
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pat.length())
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt)
{
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> result;

    constructLps(pat, lps);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;

            if (j == m)
            {
                result.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return result;
}

int main()
{
    // string txt = "aacabdc";
    // string pat = "aab";
    // string txt = "geeksforgeeks";
    // string pat = "geek";
    string txt = "aabaacaadaabaaba";
    string pat = "aaba";

    vector<int> res = search(pat, txt);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}