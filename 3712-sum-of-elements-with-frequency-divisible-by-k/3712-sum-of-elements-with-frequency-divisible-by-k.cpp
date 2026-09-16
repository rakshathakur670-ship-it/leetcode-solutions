class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int freq[101] = {0};

        // Count frequency of each element
        for (int x : nums) {
            freq[x]++;
        }

        int sum = 0;

        // Add elements whose frequency is divisible by k
        for (int x = 1; x <= 100; x++) {
            if (freq[x] > 0 && freq[x] % k == 0) {
                sum += x * freq[x];
            }
        }

        return sum;
    }
};