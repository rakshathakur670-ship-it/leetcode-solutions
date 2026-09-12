class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;

        // freq[f] = number of item types having factor f
        vector<int> freq(MAXF + 1, 0);

        int minPrice = INT_MAX;

        for (auto &item : items) {
            int f = item[0];
            int p = item[1];

            freq[f]++;
            minPrice = min(minPrice, p);
        }

        // gain[f] = number of item types j such that f divides factor[j].
        vector<int> gain(MAXF + 1, 0);

        for (int f = 1; f <= MAXF; ++f) {
            for (int multiple = f; multiple <= MAXF; multiple += f) {
                gain[f] += freq[multiple];
            }
        }

        /*
         * dp[b] = maximum number of copies obtained by using
         * exactly b dollars to buy the FIRST copy of selected
         * item types.
         *
         * Each item can be activated at most once.
         */
        vector<int> dp(budget + 1, 0);

        for (auto &item : items) {
            int f = item[0];
            int price = item[1];

            if (price > budget)
                continue;

            int value = gain[f];

            // 0/1 knapsack: iterate backwards.
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + value);
            }
        }

        int answer = 0;

        for (int spent = 0; spent <= budget; ++spent) {
            // After activating some item types, use the remaining
            // money for as many copies as possible of the cheapest item.
            int extra = (budget - spent) / minPrice;
            answer = max(answer, dp[spent] + extra);
        }

        return answer;
    }
};