class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& n, int tar) {
        int s = n.size();
        vector<vector<int>> ans;

        sort(n.begin(), n.end()); // O(nlogn)

        for (int i = 0; i < s; i++) { // O(n)
            if (i > 0 && n[i] == n[i - 1])
                continue;

            for (int j = i + 1; j < s; ) { // O(n)
                int p = j + 1, q = s - 1;

                while (p < q) { // O(n)
                    long long sum = ((long long) n[i] + (long long) n[j] +(long long) n[p] +(long long) n[q]);

                    if (sum > tar) {
                        q--;
                    } else if (sum < tar) {
                        p++;
                    } else {
                        // sum == tar
                        ans.push_back({n[i], n[j], n[p], n[q]});
                        p++, q--;
                        while (p < q && n[p] == n[p - 1])
                            p++;
                    }
                }
                j++;
                while (j < s && n[j] == n[j - 1])
                    j++;
            }
        }
        //  TC O(nlogn + n cube)
        return ans;
    }
};