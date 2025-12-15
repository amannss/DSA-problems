class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int j = 0;  // left pointer

        for (int i = 0; i < prices.size(); i++) {  // right pointer
            if (i > 0 && prices[i] != prices[i - 1] - 1) {
                j = i;   // reset window
            }
            ans += (i - j + 1);
        }

        return ans;
    }
};
