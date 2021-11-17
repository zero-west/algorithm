class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        vector<int> maxProfit(100001, 0);
        for (int i = 0; i < difficulty.size(); i++) {
            maxProfit[difficulty[i]] = max(maxProfit[difficulty[i]], profit[i]);
        }
        for (int i = 2; i < maxProfit.size(); i++) {
            maxProfit[i] = max(maxProfit[i], maxProfit[i - 1]);
        }

        int result = 0;
        for (const auto &ability: worker) {
            result += maxProfit[ability];
        }

        return result;
    }
};

