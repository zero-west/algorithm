#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> result = {};
    vector<int> emptyVec;

    void dfs(int idx, vector<int> &candidate, vector<int> &nums) {
        if (idx == nums.size()) return;

        result.emplace_back(candidate);

        for (int k = idx + 1; k < nums.size(); k++) {
            candidate.emplace_back(nums[k]);
            dfs(k, candidate, nums);
            candidate.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        dfs(-1, emptyVec, nums);
        return result;
    }
};
