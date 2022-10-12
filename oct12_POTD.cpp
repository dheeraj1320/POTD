#include <bits/stdc++.h>
using namespace std;

string maxSum(string str, char x[], int b[], int n)
{

    unordered_map<char, int> m; // Stores updated ASCII values
    int len = str.length(), st = 0, end = 0, sum = 0, maxSum = INT_MIN;
    string ans = "";

    for (int i = 0; i < n; i++)
        m[x[i]] = b[i]; // storing updated ASCII values in map

    while (end < len)
    {

        int val = (m.find(str[end]) != m.end()) ? m[str[end]] : (int)str[end];
        sum += val;

        if (sum > maxSum)
        {
            maxSum = sum;
            ans = str.substr(st, end - st + 1);
        }

        if (sum < 0)
        {
            sum = 0;
            st = end + 1;
        }

        end++;
    }

    return ans;
}

int main()
{

    string str;
    cin >> str;

    int n;
    cin >> n;

    char x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];

    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    cout << maxSum(str, x, b, n);
}