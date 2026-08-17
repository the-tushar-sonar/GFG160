#include <bits/stdc++.h>
using namespace std;

// vector<int> search(string &pat, string &txt)
// void search(string &pat, string &txt)
// {
//     // cout << "txt : " << txt << endl;
//     // cout << "pat : " << pat << endl;

//     vector<int> result;
//     int count = 0;
//     for (int i = 0; i < txt.size(); i++)
//     {
//         result.push_back(i);
//         for (int j = 0; j < pat.size(); j++)
//         {
//             cout << "\n"
//                  << txt[j] << "\t" << pat[j];
//             if (txt[i] == pat[j])
//             {
//                 cout << "\t" << count << endl;
//                 count++;
//                 break;
//             }

//             if (txt[j] != pat[j])
//             {
//                 cout << "\tNot matching..." << endl;
//                 break;
//             }
//         }
//         if (count == pat.size())
//         {
//             result.push_back(i);
//             count = 0;
//         }
//     }

//     for (int num : result)
//     {
//         cout << "num :" << num << " ";
//     }
//     cout << endl;
// }

void search(string &pat, string &txt)
{
    vector<int> result;
    int count = 0;

    for (int i = 0; i < txt.size(); i++)
    {
        cout << "\n========================================\n";
        cout << "Starting from text index i = " << i << endl;
        cout << "========================================\n";

        for (int j = 0; j < pat.size(); j++)
        {
            cout << "i = " << i
                 << ", j = " << j
                 << " | txt[" << i + j << "] = '" << txt[i + j] << "'"
                 << " | pat[" << j << "] = '" << pat[j] << "'";

            if (txt[i + j] == pat[j])
            {
                count++;
                cout << " --> MATCH"
                     << " | count = " << count << endl;

                // break;
            }
            else
            {
                cout << " --> NOT MATCH"
                     << " | count = " << count << endl;

                break;
            }
        }

        if (count == pat.size())
        {
            cout << ">>> PATTERN FOUND at index " << i << endl;

            result.push_back(i);
            count = 0;
        }
    }

    cout << "\nFinal result: ";

    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;
}
int main()
{
    string txt = "geeksforgeeks";
    string pat = "geek";

    search(pat, txt);

    return 0;
}