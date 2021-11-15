#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> result = {};
    vector<int> emptyVec = {};

    void dfs(int curSum, int idx, int target, vector<int> &candidates, vector<int> &combine) {
        if (curSum == target) {
            result.emplace_back(combine);
            return;
        }

        for (int k = idx; k < candidates.size(); k++) {
            if (curSum + candidates[k] > target) continue;

            combine.emplace_back(candidates[k]);
            dfs(curSum + candidates[k], k, target, candidates, combine);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        dfs(0, 0, target, candidates, emptyVec);
        return result;
    }
};
