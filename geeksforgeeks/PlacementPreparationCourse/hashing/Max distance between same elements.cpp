// Given an array with repeated elements, the task is to find the maximum distance between two occurrences of an element.

// Input:

// The first line of input will contain no of test cases T . Then T test cases follow . Each test case contains 2 lines. The first line of each test case contains an integer N denoting the number of elements in the array, the next line contains N space separated integer's.

// Output:

// For each test case in new line print the Maximum distance between two occurrences of an element

// Constraints:

// 1<=T<=100

// 1<=N<=1000

// Example:

// Input

// 2
// 6
// 1 1 2 2 2 1
// 12
// 3 2 1 2 1 4 5 8 6 7 4 2

// Output

// 5
// 10

// Explanation

// Test case 1:
// arr[] = {1, 1, 2, 2, 2, 1}
// Max Distance: 5
// Distance for 1 is: 5-0 = 5
// Distance for 2 is : 4-2 = 2
// Max Distance 5

// Test case 2:
// arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}
// Max Distance 10
// maximum distance for 2 is 11-1 = 10
// maximum distance for 1 is 4-2 = 2
// maximum distance for 4 is 10-5 = 5

// Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << maxDistance(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends

// your task is to complete this function
int maxDistance(int arr[], int n)
{
    //Code here
    // if(n==1)
    //     return 0;

    unordered_map<int, int> mp;
    int curr_max = 0;
    int max_dis = 0;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            if (i - mp[arr[i]] > max_dis)
            {
                max_dis = i - mp[arr[i]];
            }
        }
        else
        {
            mp.insert(pair<int, int>(arr[i], i));
        }
    }
    return max_dis;
}