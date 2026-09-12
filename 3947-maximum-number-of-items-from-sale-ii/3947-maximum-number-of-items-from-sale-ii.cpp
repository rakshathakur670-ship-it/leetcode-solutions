
class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // cnt[f] = number of item types with factor f
        vector<int> cnt(n + 1, 0);

        long long minPrice = LLONG_MAX;

        for (auto &item : items) {
            int factor = item[0];
            long long price = item[1];

            cnt[factor]++;
            minPrice = min(minPrice, price);
        }

        /*
         * multiples[f] = number of item types j whose factor
         * is divisible by f.
         */
        vector<int> multiples(n + 1, 0);

        for (int f = 1; f <= n; ++f) {
            for (int x = f; x <= n; x += f) {
                multiples[f] += cnt[x];
            }
        }

        /*
         * For item i:
         *
         * gain = number of OTHER item types it can give for free.
         *
         * The first gain copies of item i are each worth:
         *   1 purchased + 1 free = 2 total copies.
         *
         * Every copy after that is worth only 1.
         */
        vector<pair<long long, long long>> bonus;

        for (auto &item : items) {
            int factor = item[0];
            long long price = item[1];

            long long gain = multiples[factor] - 1;

            if (gain > 0 && price < 2 * minPrice) {
                bonus.push_back({price, gain});
            }
        }

        // All bonus copies have value 2, so process cheapest first.
        sort(bonus.begin(), bonus.end());

        // If we buy only ordinary copies, this is our baseline.
        long long answer = budget / minPrice;

        long long spent = 0;
        long long bonusCount = 0;

        for (auto &[price, available] : bonus) {
            if (spent >= budget)
                break;

            // Number of bonus copies we can afford from this item.
            long long take = min(
                available,
                (budget - spent) / price
            );

            spent += take * price;
            bonusCount += take;

            // Each bonus purchase gives 2 total copies.
            // Remaining money buys ordinary copies at minPrice.
            long long total =
                2 * bonusCount +
                (budget - spent) / minPrice;

            answer = max(answer, total);
        }

        return answer;
    }
};

