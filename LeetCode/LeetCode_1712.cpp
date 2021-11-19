class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        int N = nums.size();
        int MOD = 1000000007;

        for (int i = 1; i < N; i++) {
            nums[i] += nums[i - 1];
        }

        int result = 0;
        for (int i = 1; i < N - 1; i++) {
            auto l = lower_bound(nums.begin() + i, nums.end(), nums[i - 1] * 2);
            auto r = upper_bound(nums.begin() + i, nums.end() - 1, (nums.back() - nums[i - 1]) / 2 + nums[i - 1]);
            result += max((int) (r - l), 0);
            result %= MOD;
        }

        return result;
    }
};

