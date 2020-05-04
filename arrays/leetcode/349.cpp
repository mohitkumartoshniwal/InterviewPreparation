//Intersection of Two Arrays

//https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_set<int> hs;
        unordered_set<int> ans;
        for (int i : nums1)
        {
            hs.insert(i);
        }

        for (int i : nums2)
        {
            if (hs.find(i) != hs.end())
            {
                ans.insert(i);
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};

//another nice way

//https://leetcode.com/problems/intersection-of-two-arrays/discuss/213605/Java-1ms-beats-99.85