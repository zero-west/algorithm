class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int N = arr.size();

        int left = 0, right = N - 1;
        while (left < right && arr[left + 1] >= arr[left]) {
            left++;
        }
        if (left == right) return 0;

        while (right > left && arr[right - 1] <= arr[right]) {
            right--;
        }

        int result = min(N - left - 1, right);
        int j = right;

        for (int i = 0; i < left + 1; i++) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
            } else if (j < N - 1) {
                j++;
            } else {
                break;
            }
        }

        return result;
    }
};

