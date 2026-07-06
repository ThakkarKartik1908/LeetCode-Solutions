class Solution {
public:
    int subarraySum(vector<int>& n, int k) {
        int ans = 0, s = n.size(), count = 0;
        for (int i = 0; i < s; i++) {

            int sum = 0;
            for (int j = i; j < s; j++) {
                sum = sum + n[j];

                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};