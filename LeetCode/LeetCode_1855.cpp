class Solution {
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2) {
        int p = 0, q = 0;

        int result = 0;
        while (p < nums1.size() && q < nums2.size()) {
            if (nums1[p] <= nums2[q]) {
                result = max(result, q - p);
                q++;
            } else {
                p++;
            }
        }

        return result;
    }
};

