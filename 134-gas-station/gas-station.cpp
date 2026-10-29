class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0, totcost = 0;

        // unique solution alwaya exists
        int start = 0, currGas = 0;
        for (int i = 0; i < gas.size(); i++) {
            totGas += gas[i];
            totcost += cost[i];
            currGas += (gas[i] - cost[i]);

            if (currGas < 0) {
                start = i + 1;
                currGas = 0;
            }
        }

        return totGas < totcost ? -1 : start;
    }
};