//https://leetcode.com/problems/kth-largest-element-in-an-array/

//for more optimized versions check below
//https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        //to find kth smallest
        //for min heap
        //priority_queue <int, vector<int>, greater<int>> g = gq;
        priority_queue<int> p;
        int ans;
        for (int i : nums)
        {
            p.push(i);
        }
        for (int i = 0; i < k; i++)
        {
            ans = p.top();
            p.pop();
        }

        return ans;
    }
};

//or

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        while(--k){
            pop_heap(nums.begin(),nums.end());
            nums.pop_back();
        }
        return nums[0];
    }
};
*/