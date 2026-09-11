class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        int start = 0;
        int tank = 0;

        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];

            totalGas += gas[i];
            totalCost += cost[i];

            tank += gain;

            // Current start cannot reach station i + 1
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // Not enough total gas to complete the circuit
        if (totalGas < totalCost)
            return -1;

        return start;
    }
};