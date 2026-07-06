class Solution {
public:
    int subarraySum(vector<int>& n, int k) {
        int s = n.size(), count = 0; // count store ans
        vector<int> prefixSum(s, 0);

        prefixSum[0] = n[0];
        for (int i = 1; i < s; i++) {
            prefixSum[i] = prefixSum[i - 1] + n[i];
        }

        unordered_map<int, int> m; // ps ,freq

        for (int j = 0; j < s; j++) {
            if (prefixSum[j] == k)
                count++;

            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) { // exist
                count += m[val];
            }

            if (m.find(prefixSum[j]) == m.end()) {
                // not exist
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }
        return count;
    }
};