class Solution {
public:
    void getPerms(vector<int>& n, int idx, vector<vector<int>>& ans) {
        if (idx == n.size()) {
            ans.push_back({n});
        }

        for (int i = idx; i < n.size(); i++) {
            swap(n[idx], n[i]); // idx placr => ith element choice
            getPerms(n, idx + 1, ans);

            swap(n[idx], n[i]); // backtracking
        }
    }
    vector<vector<int>> permute(vector<int>& n) {
        vector<vector<int>> ans;
        getPerms(n, 0, ans);

            return ans;
    }
};