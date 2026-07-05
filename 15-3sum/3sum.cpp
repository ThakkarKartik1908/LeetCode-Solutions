class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& n) {
        int sz = n.size();
        vector<vector<int>> ans; // O(UniqueTriplets)
        sort(n.begin(), n.end());// O(nlogn)

        for (int i = 0; i < sz; i++) { //O(n)
            int j = i + 1, k = sz - 1;

            if (i > 0 && n[i] == n[i - 1]) { // for i not duplicates
                continue;
            }

            while (j < k) { //O(n)

                int  sum = n[i] + n[j] + n[k];

                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    // sum==0
                    ans.push_back({n[i], n[j], n[k]});
                    j++, k--;
                    while (j < k && n[j] == n[j - 1]) { //// for j not duplicates
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};