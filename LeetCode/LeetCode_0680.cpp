/**
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */
class Solution {
public:
    bool solve(string s, int p, int q, int removeCount) {
        if (removeCount > 1) {
            return false;
        }

        while (p < q) {
            if (s[p] == s[q]) {
                p++;
                q--;
            } else {
                return solve(s, p + 1, q, removeCount + 1) || solve(s, p, q - 1, removeCount + 1);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        return solve(s, 0, s.length() - 1, 0);
    }
};
