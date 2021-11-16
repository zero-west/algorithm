class Solution {
public:
    int minSwaps(string s) {
        int result = 0, count = 0;

        for (const auto &ch: s) {
            if (ch == '[') {
                count++;
            } else {
                if (count == 0) {
                    result++;
                    count++;
                } else {
                    count--;
                }
            }
        }
        return result;
    }
};
