#include <bits/stdc++.h>
using namespace std;

int maximizeSum(int arr[], int n)
{
    unordered_map<int, int> m;
    int ans = 0, maxEl = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxEl = max(maxEl, arr[i]);
        m[arr[i]]++; // storing count of each
    }                // number in map

    int i = maxEl;
    while (i > 0)
    {

        if (m[i] > 0)
        {
            ans += i;
            m[i - 1]--; // decreasing Ai-1 count
            m[i]--;     // decreasing Ai count
        }
        else
        {
            i--;
        }
    }
    return ans;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maximizeSum(arr, n);
}