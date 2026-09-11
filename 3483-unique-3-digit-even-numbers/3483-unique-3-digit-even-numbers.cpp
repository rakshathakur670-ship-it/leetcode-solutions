class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;
            int b = (x / 10) % 10;
            int c = x % 10;

            // Check whether we have enough copies
            // of each digit.
            vector<int> used(10, 0);
            used[a]++;
            used[b]++;
            used[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (used[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};