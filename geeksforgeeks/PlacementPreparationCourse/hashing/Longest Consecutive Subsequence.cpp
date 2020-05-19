// Given an array A of integers. The task is to complete the function which returns an integer denoting the length of the longest sub-sequence such that elements in the sub-sequence are consecutive integers, the consecutive numbers can be in any order.

// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N. Then in the next line are N space separated values of the array A.

// Output:
// For each test case in a new line output will be the length of the longest consecutive increasing sub-sequence present in the array A[ ].

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 106
// 1 <= Ai <= 108

// Example(To be used only for expected output):
// Input:
// 2
// 7
// 1 9 3 10 4 20 2
// 11
// 36 41 56 35 44 33 34 92 43 32 42
// Output:
// 4
// 5

// Explanation:
// Testcase 1: Logest consecutive subsequence is 1, 2, 3, 4 of length 4.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

int findLongestConseqSubseq(int[], int);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        // input array elements
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << findLongestConseqSubseq(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends

// function to find longest consecutive subsequence
// n : size of array
// arr[] : input array
int findLongestConseqSubseq(int arr[], int n)
{
    //Your code here
    unordered_set<int> s;

    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    int ans = INT_MIN;
    for (int i : s)
    {
        //first element in sequence
        if (s.find(i - 1) == s.end())
        {

            int j = i;
            while (s.find(j) != s.end())
                j++;

            ans = max(ans, j - i);
        }
    }
    return ans;
}