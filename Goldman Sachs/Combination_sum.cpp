// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice,
// and the combinations may be returned in any order.
//Example 1:
// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<int>> &ans, int k, int n, vector<int> &temp, int idx)
    {
        if (n == 0 && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        if (temp.size() > k || n < 0 || idx > n)
        {
            return;
        }
        for (int i = idx; i <= 9; i++)
        {
            temp.push_back(i);
            solve(ans, k, n - i, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, k, n, temp, 1);
        return ans;
    }
};
