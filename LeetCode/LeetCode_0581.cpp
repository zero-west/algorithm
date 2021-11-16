class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int N = nums.size();

        int right = N, maxNum = nums[0];
        for (int i = 1; i < N; i++) {
            if (nums[i] < maxNum) {
                right = i;
            }
            maxNum = max(maxNum, nums[i]);
        }
        if (right == N) return 0;

        int left = -1, minNum = nums[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            if (nums[i] > minNum) {
                left = i;
            }
            minNum = min(minNum, nums[i]);
        }

        return right - left + 1;
    }
};

