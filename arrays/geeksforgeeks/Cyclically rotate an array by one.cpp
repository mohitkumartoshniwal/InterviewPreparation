//https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    int n;

    while (t--)
    {
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int last = a[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = last;

        for (int i : a)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    //code
    return 0;
}