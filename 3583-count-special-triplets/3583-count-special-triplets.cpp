class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();

        unordered_map<int, int> rightFreq, leftFreq;
        rightFreq.reserve(n * 2);
        leftFreq.reserve(n * 2);

        for(int x : nums) 
            rightFreq[x]++;

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            rightFreq[nums[i]]--;

            int vals = nums[i] * 2;

            if(leftFreq.count(vals) && rightFreq.count(vals)) {
                ans += (1LL * leftFreq[vals] * rightFreq[vals]) % mod;
            }

            leftFreq[nums[i]]++;
        }

        return ans % mod;
    }
};
